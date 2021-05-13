//
//  PLVCloudClassConfigModule.m
//  PLV-CloudClassUniPlugin
//
//  Created by ysh on 2020/11/6.
//

#import "PLVCloudClassConfigModule.h"
#import "PLVCloudClassUtils.h"
#import <PolyvCloudClassSDK/PLVLiveVideoConfig.h>
#import <PolyvCloudClassSDK/PLVWVodVideoConfig.h>
#import "PolyvUniCloudClassConfig.h"

static NSString *viewerId;
static NSString *viewerName;
static NSString *viewerAvatar;

@implementation PLVCloudClassConfigModule

WX_EXPORT_METHOD(@selector(setConfig:callback:))

-(void)setConfig:(NSDictionary*)options callback:(WXModuleKeepAliveCallback)callback {
    NSString *appId = [PLVCloudClassUtils stringValueWithDictionary:options forKey:@"appId" defaultValue:nil];
    NSString *appSecret = [PLVCloudClassUtils stringValueWithDictionary:options forKey:@"appSecret" defaultValue:nil];
    NSString *userId = [PLVCloudClassUtils stringValueWithDictionary:options forKey:@"userId" defaultValue:nil];
    
    //判空
    if(![PLVCloudClassUtils isValidString:appId]) {
        [self callbackResultOnce:callback isSucceed:NO errMsg:@"appId 不能为空"];
        return;
    }
    if(![PLVCloudClassUtils isValidString:appSecret]) {
        [self callbackResultOnce:callback isSucceed:NO errMsg:@"appSecret 不能为空"];
        return;
    }
    if(![PLVCloudClassUtils isValidString:userId]) {
        [self callbackResultOnce:callback isSucceed:NO errMsg:@"userId 不能为空"];
        return;
    }
    
    PLVLiveVideoConfig *liveConfig = [PLVLiveVideoConfig sharedInstance];
    liveConfig.enableHttpDNS = NO;
    liveConfig.appId = appId;
    liveConfig.userId = userId;
    liveConfig.appSecret = appSecret;
    [self callbackResultOnce:callback isSucceed:YES errMsg:@""];
}

WX_EXPORT_METHOD(@selector(setViewerInfo:callback:))

-(void)setViewerInfo:(NSDictionary*)options callback:(WXModuleKeepAliveCallback)callback {
    //判空
    NSString *optViewerID = [PLVCloudClassUtils stringValueWithDictionary:options forKey:@"viewerId" defaultValue:nil];
    if(![PLVCloudClassUtils isValidString:optViewerID]) {
        [self callbackResultOnce:callback isSucceed:NO errMsg:@"viewerId 不能为空"];
        return;
    }
    
    NSString *optViewerImg = [PLVCloudClassUtils stringValueWithDictionary:options forKey:@"viewerAvatar" defaultValue:nil];
    if(![PLVCloudClassUtils isValidString:optViewerImg]) { //默认头像
        optViewerImg = @"https://s1.videocc.net/face.png";
    }
    
    NSString *optViewerName = [PLVCloudClassUtils stringValueWithDictionary:options forKey:@"viewerName" defaultValue:nil];
    NSString *param4 = [PLVCloudClassUtils stringValueWithDictionary:options forKey:@"param4" defaultValue:nil];
    NSString *param5 = [PLVCloudClassUtils stringValueWithDictionary:options forKey:@"param5" defaultValue:nil];
    
    viewerId = optViewerID;
    viewerName = optViewerName;
    viewerAvatar = optViewerImg;
    
    //配置直播后台统计参数
    [PLVLiveVideoConfig setViewLogParam:viewerId param2:viewerName param4:param4 param5:param5];
    //配置点播后台统计参数
    [PLVWVodVideoConfig setViewLogViewerId:viewerId viewerName:viewerName];
    
    [self callbackResultOnce:callback isSucceed:YES errMsg:@""];
}


/**
 设置跑马灯相关参数设置参数
 */
WX_EXPORT_METHOD(@selector(setMarqueeConfig:callback:))

- (void)setMarqueeConfig:(NSDictionary*)options
                callback:(WXModuleKeepAliveCallback)callback {
    NSString *code = [PLVCloudClassUtils stringValueWithDictionary:options forKey:@"code" defaultValue:nil];
    if([PLVCloudClassUtils isValidString:code]) {
        [PolyvUniCloudClassConfig sharedInstance].code = code;
    }
    [self callbackResultOnce:callback isSucceed:YES errMsg:@""];
}

-(void)callbackResultOnce:(WXModuleKeepAliveCallback)callback
                isSucceed:(BOOL)isSucceed
                   errMsg:(NSString*)errMsg {
    if (!isSucceed) {
        //        NSLog(@"errMsg: %@",errMsg);
    }
    
    if(callback){
        callback(@{@"isSuccess": @(isSucceed), @"errMsg": errMsg}, NO);
    }
}

+(NSString *)viewerId {
    return viewerId;
}

+(NSString *)viewerName {
    return viewerName;
}

+(NSString *)viewerAvatar {
    return viewerAvatar;
}

@end
