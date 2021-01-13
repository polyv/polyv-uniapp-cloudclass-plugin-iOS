//
//  PLVCloudClassPlayModule.m
//  PLV-CloudClassUniPlugin
//
//  Created by yshon 2020/11/6.
//

#import "PLVCloudClassPlayModule.h"
#import "PLVCloudClassConfigModule.h"
#import "PLVCloudClassUtils.h"
#import "PLVLiveViewController.h"
#import "PLVVodViewController.h"
#import <PolyvCloudClassSDK/PLVLiveVideoAPI.h>
#import <PolyvCloudClassSDK/PLVLiveVideoConfig.h>

@implementation PLVCloudClassPlayModule

WX_EXPORT_METHOD(@selector(startLive:callback:))

-(void)startLive:(NSDictionary*)options callback:(WXModuleKeepAliveCallback)callback{
    NSString *channelId = [PLVCloudClassUtils stringValueWithDictionary:options forKey:@"channelId" defaultValue:nil];
    //判空
    if(![PLVCloudClassUtils isValidString:channelId]){
        [self callbackResultOnce:callback isSucceed:NO errMsg:@"channelId 不能为空"];
        return;
    }

    PLVLiveVideoConfig *liveConfig = [PLVLiveVideoConfig sharedInstance];
    liveConfig.channelId = channelId;

    __weak typeof(self) weakSelf = self;
    [PLVLiveVideoAPI verifyPermissionWithChannelId:liveConfig.channelId.integerValue vid:@"" appId:liveConfig.appId userId:liveConfig.userId appSecret:liveConfig.appSecret completion:^(NSDictionary * _Nonnull data) {
        /// 设置聊天室相关的私有服务器的域名
        [PLVLiveVideoConfig setPrivateDomainWithData:data];
        ///获取直播状态
        [PLVLiveVideoAPI liveStatus2:liveConfig.channelId completion:^(NSString *liveType, PLVLiveStreamState liveState) {
            ///获取频道菜单
            [PLVLiveVideoAPI getChannelMenuInfos:liveConfig.channelId.integerValue completion:^(PLVLiveVideoChannelMenuInfo *channelMenuInfo) {
                [weakSelf presentLiveViewControllerWithLiveState:liveState liveType:liveType channelMenuInfo:channelMenuInfo];
                [weakSelf callbackResultOnce:callback isSucceed:YES errMsg:@""];
            } failure:^(NSError *error) {
                [weakSelf callbackResultOnce:callback isSucceed:NO errMsg:error.localizedDescription];
            }];
        } failure:^(NSError *error) {
            [weakSelf callbackResultOnce:callback isSucceed:NO errMsg:error.localizedDescription];
        }];

    } failure:^(NSError *error) {
        [weakSelf callbackResultOnce:callback isSucceed:NO errMsg:error.localizedDescription];
    }];
}

WX_EXPORT_METHOD(@selector(startPlayback:callback:))

-(void)startPlayback:(NSDictionary*)options callback:(WXModuleKeepAliveCallback)callback{

    NSString *channelId = [PLVCloudClassUtils stringValueWithDictionary:options forKey:@"channelId" defaultValue:nil];
    if(![PLVCloudClassUtils isValidString:channelId]){
        [self callbackResultOnce:callback isSucceed:NO errMsg:@"channelId 不能为空"];
        return;
    }
    
    NSString *videoId = [PLVCloudClassUtils stringValueWithDictionary:options forKey:@"videoId" defaultValue:nil];
    if(![PLVCloudClassUtils isValidString:videoId]){
        [self callbackResultOnce:callback isSucceed:NO errMsg:@"videoId 不能为空"];
        return;
    }
    
    BOOL vodList = [options[@"videoType"] boolValue];

    PLVLiveVideoConfig *liveConfig = [PLVLiveVideoConfig sharedInstance];
    liveConfig.channelId = channelId;
    liveConfig.vodId = videoId;

    __weak typeof(self) weakSelf = self;
    [PLVLiveVideoAPI verifyPermissionWithChannelId:liveConfig.channelId.integerValue vid:videoId appId:liveConfig.appId userId:liveConfig.userId appSecret:liveConfig.appSecret completion:^(NSDictionary * _Nonnull data) {
        /// 设置聊天室相关的私有服务器的域名
        [PLVLiveVideoConfig setPrivateDomainWithData:data];

        [PLVLiveVideoAPI getVodType:videoId completion:^(BOOL vodType) {
            if(vodType && vodList) {
                [weakSelf callbackResultOnce:callback isSucceed:NO errMsg:@"三分屏场景暂不支持使用点播列表播放"];
                return;
            }

            [PLVLiveVideoAPI getChannelMenuInfos:liveConfig.channelId.integerValue completion:^(PLVLiveVideoChannelMenuInfo * _Nonnull channelMenuInfo) {

                [weakSelf presentVodViewControllerWithVodType:vodType vodList:vodList channelMenuInfo:channelMenuInfo];
                [weakSelf callbackResultOnce:callback isSucceed:YES errMsg:@""];

            } failure:^(NSError * _Nonnull error) {
                [weakSelf callbackResultOnce:callback isSucceed:NO errMsg:error.localizedDescription];
            }];
        } failure:^(NSError * _Nonnull error) {
            [weakSelf callbackResultOnce:callback isSucceed:NO errMsg:error.localizedDescription];
        }];
        } failure:^(NSError *error) {
            [weakSelf callbackResultOnce:callback isSucceed:NO errMsg:error.localizedDescription];
    }];
}

-(void)callbackResultOnce:(WXModuleKeepAliveCallback)callback isSucceed:(BOOL)isSucceed errMsg:(NSString*)errMsg {
    if (!isSucceed) {
//        NSLog(@"errMsg: %@",errMsg);
    }
    if(callback) {
        callback(@{@"isSuccess": @(isSucceed), @"errMsg": errMsg}, NO);
    }
}

-(void)presentLiveViewControllerWithLiveState:(PLVLiveStreamState)liveState
                                        liveType:(NSString*)liveType
                                 channelMenuInfo:(PLVLiveVideoChannelMenuInfo *)channelMenuInfo {
    //todo 对rtc类型判断

    //跳转配置
    PLVLiveViewController *liveVC = [PLVLiveViewController new];
    liveVC.liveType = [@"ppt" isEqualToString:liveType] ? PLVLiveViewControllerTypeCloudClass:PLVLiveViewControllerTypeLive;
    liveVC.liveState = liveState;
    liveVC.viewer = NO;
    liveVC.channelMenuInfo = channelMenuInfo;

    liveVC.nickName = [PLVCloudClassConfigModule viewerName];
    liveVC.avatarUrl = [PLVCloudClassConfigModule viewerAvatar];
    liveVC.viewerId = [PLVCloudClassConfigModule viewerId];

    [self presentVC:liveVC];
}

 - (void)presentVodViewControllerWithVodType:(BOOL)vodType vodList:(BOOL)vodList channelMenuInfo:(PLVLiveVideoChannelMenuInfo *)channelMenuInfo {

     PLVVodViewController *vodVC = [PLVVodViewController new];
     vodVC.vodType = vodType ? PLVVodViewControllerTypeCloudClass : PLVVodViewControllerTypeLive;
     vodVC.channelMenuInfo = channelMenuInfo;
     vodVC.vodList = vodList;
     [self presentVC:vodVC];
 }

- (void)presentVC:(UIViewController *)vctrl {
    UIViewController *rootViewController = [UIApplication sharedApplication].keyWindow.rootViewController;
    UIViewController *parentVC = [[self class] findCurrentShowingViewControllerFrom:rootViewController];
    vctrl.modalPresentationStyle = UIModalPresentationFullScreen;
    [parentVC presentViewController:vctrl animated:YES completion:nil];
}

//跳转到原生的UIViewController：https://nativesupport.dcloud.net.cn/NativePlugin/course/ios?id=q-%e5%a6%82%e4%bd%95%e8%b7%b3%e8%bd%ac%e5%8e%9f%e7%94%9f-uiviewcontroller

//获取当前显示的UIViewController
+(UIViewController *)dc_findCurrentShowingViewController{
    //获取当前活动窗口的根识图
    UIViewController* vc = [UIApplication sharedApplication].keyWindow.rootViewController;
    UIViewController *currentShowingVC = [self findCurrentShowingViewControllerFrom:vc];
    return currentShowingVC;
}

+(UIViewController *)findCurrentShowingViewControllerFrom:(UIViewController*)vc{
    //递归方法
    UIViewController *currentShowingVC;
    if([vc presentedViewController]){
        //当前视图是被presented出来的
        UIViewController *nextRootVC = [vc presentedViewController];
        currentShowingVC = [self findCurrentShowingViewControllerFrom:nextRootVC];
    } else if([vc isKindOfClass:[UITabBarController class]]){
        // 根视图为UITabBarController
        UIViewController *nextRootVC = [(UITabBarController *)vc selectedViewController];
        currentShowingVC = [self findCurrentShowingViewControllerFrom:nextRootVC];
    } else if ([vc isKindOfClass:[UINavigationController class]]){
        // 根视图为UINavigationController
        UIViewController *nextRootVC = [(UINavigationController *)vc visibleViewController];
        currentShowingVC = nextRootVC;
//        currentShowingVC = [self findCurrentShowingViewControllerFrom:nextRootVC];

    } else {
        // 根视图为非导航类
        currentShowingVC = vc;
    }

    return currentShowingVC;
}

@end
