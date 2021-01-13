//
//  PLVPlayerControllerPrivateProtocol.h
//  PolyvBusinessSDK
//
//  Created by zykhbl on 2018/9/18.
//  Copyright © 2018年 polyv. All rights reserved.
//

#if __has_include(<PolyvIJKMediaFramework/PolyvIJKMediaFramework.h>)
    #import <PolyvIJKMediaFramework/PLVIJKFFMoviePlayerController.h>
    #define PolyvIJKMediaFramework "PolyvIJKMediaFramework"
#elif __has_include(<IJKMediaFramework/IJKMediaFramework.h>)
    #import <IJKMediaFramework/IJKMediaFramework.h>
#else
    #define PLV_BLOCKED_FILE
    #warning 开播端打包不支持云课堂SDK使用
#endif

/// 广告类型
typedef NS_ENUM(NSInteger, PLVPlayerControllerADType) {
    /// 图片暖场广告
    PLVPlayerControllerADTypeImage = 1,
    /// 视频暖场广告
    PLVPlayerControllerADTypeVideo = 2
};

#ifndef PLV_BLOCKED_FILE

//!!!播放器私有接口，只提供给PolyvCloudClassSDK层的播放器子类调用，不提供给Demo层使用
@protocol PLVPlayerControllerPrivateProtocol <NSObject>

/// 主播放器，播放直播或正片
#ifdef PolyvIJKMediaFramework
@property (nonatomic, strong) PLVIJKFFMoviePlayerController *mainPlayer;
#else
@property (nonatomic, strong) IJKFFMoviePlayerController *mainPlayer;
#endif

/// loading view
@property (nonatomic, strong) UIActivityIndicatorView *activityView;
/// loading speed
@property (nonatomic, strong) UILabel *loadSpeedLabel;

/// 直播，有视频暖场，则默认播放暖场
@property (nonatomic, assign, readonly) BOOL adLogic;
/// 播放是否已暂停
@property (nonatomic, assign) BOOL paused;

@optional
/// !!!以下方法为播放器父类私有接口，只在父类实现，子类不重写!!!

/// 清空主播放器资源
- (void)clearMainPlayer;

/// 改变播放状态
- (void)playStatus:(BOOL)playable;

/// 单独改变video视图的显示状态，而不涉及playable
- (void)showVideoView:(BOOL)show;

/// 当前播放器不可播放
- (void)unplayable;

/// 显示log消息
- (void)showMessage:(NSString *)message;

/// 播放广告(暖场)
- (void)playAD:(NSURL *)adUrl adType:(PLVPlayerControllerADType)adType adLogic:(BOOL)adLogic;

/// 加载视频相关的窗口（背景窗口，loading窗口，视频窗口）
- (void)loadViewsInDisplayView:(UIView *)displayView;

/// 加载主播放器
- (void)loadMainPlayer:(NSURL *)url options:(PLVIJKFFOptions *)options;


/// !!!以下方法为播放器子类私有接口，只在子类实现，父类不实现!!!

/// AD播放器播放结束回调
- (void)subPlayerPlaybackDidFinish:(NSNotification *)notification;

/// 将要改变播放状态
- (void)willChangePlayStatus;

/// 主播放器加载状态变化回调
- (void)mainPlayerLoadStateDidChange;

/// 主播放器播放状态变化回调
- (void)mainPlayerPlaybackStateDidChange;

/// 主播放器播放结束回调
- (void)mainPlayerPlaybackDidFinish:(NSNotification *)notification;

/// 主播放器Seek完成回调
//- (void)mainPlayerDidSeekComplete:(NSNotification *)notification;

/// 主播放器精准Seek完成回调
//- (void)mainPlayerAccurateSeekComplete:(NSNotification *)notification;

@end

#endif
