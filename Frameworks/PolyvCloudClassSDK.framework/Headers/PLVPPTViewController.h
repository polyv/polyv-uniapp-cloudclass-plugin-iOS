//
//  PLVPPTViewController.h
//  PolyvCloudClassSDK
//
//  Created by zykhbl on 2018/9/14.
//  Copyright © 2018年 polyv. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PLVPPTViewControllerDelegate;

/// 云课堂PPT
@interface PLVPPTViewController : UIViewController

/// delegate
@property (nonatomic, weak) id<PLVPPTViewControllerDelegate> delegate;
/// PPT是否可播放
@property (nonatomic, assign) BOOL pptPlayable;
/// 视频背景图，默认显示模式 UIViewContentModeCenter
@property (nonatomic, strong) UIImageView *backgroundImgView;
/// 在socket登录成功后，把socket返回的user信息保存起来，在PPT web加载成功后调用setUser
@property (nonatomic, strong) NSDictionary *userInfo;
/// ppt加载时中间占位图的图片地址
@property (nonatomic, copy) NSString *pptBackgroundImgUrl;
/// 占位图宽度，必须带上px单位
@property (nonatomic, copy) NSString *pptBackgroundImgWidth;
/// 占位图图片颜色，格式必须为rgba(r,g,b,a)
@property (nonatomic, copy) NSString *pptBackgroundColor;

/// 刷新PPT内容
- (void)refreshPPT:(NSString *)json;

/// 刷新PPT内容（新）
- (void)refreshPPT:(NSString *)json delay:(NSUInteger)delay;

/// 设置视频SEI信息
- (void)setSeiData:(NSString *)json;

/// 双向画笔 相关函数

/// 选择画笔颜色
- (void)changeColor:(NSString *)color;

/// 进入画笔删除状态,用于直播
- (void)toDelete;

/// 是否授予画笔权限, 是否授予操作ppt权限
- (void)setPaintPermission:(BOOL)paint controlPPT:(BOOL)control;

/// 设置画板是否处于可绘制状态，close表示关闭画笔，open表示开启画笔
- (void)setPaintStatus:(NSString *)status;

/// 双向画笔 相关函数

/// 点播，开始播放PPT
- (void)videoStart:(NSString *)vid;

/// 播放
- (void)pptPlay:(long)curTime;

/// 暂停
- (void)pptPause:(long)curTime;

/// seek
- (void)pptSeek:(long)curTime;

@end

@protocol PLVPPTViewControllerDelegate <NSObject>

@optional
/// 回放点播时，PPT已经准备好播放，此时Demo才播放副屏
- (void)pptPrepare:(PLVPPTViewController *)pptVC;

/// 得到Demo回放点播视频的当前播放时间进度
- (NSTimeInterval)getCurrentTime:(PLVPPTViewController *)pptVC;

/// 改变PPT所在窗口（主屏或副屏）的底色
- (void)changePPTScreenBackgroundColor:(PLVPPTViewController *)pptVC;

/// 开启了画笔权限的连麦学员操作绘画后，把生成的笔触数据回调给Socket发送
- (void)sendPaintInfo:(PLVPPTViewController *)pptVC jsonData:(NSString *)jsonData;

/// 讲师主动切换PPT和视频窗口（status为YES代表视频在主窗口，为NO代表PPT在主窗口）
- (void)changeVideoAndPPTPosition:(BOOL)status;

@end
