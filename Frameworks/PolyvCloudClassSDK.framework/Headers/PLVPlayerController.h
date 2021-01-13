//
//  PLVPlayerController.h
//  PolyvBusinessSDK
//
//  Created by zykhbl on 2018/7/30.
//  Copyright © 2018年 polyv. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PLVPlayerControllerDelegate;

/// 播放器基类
@interface PLVPlayerController : NSObject

/// delegage
@property (nonatomic, weak) id<PLVPlayerControllerDelegate> delegate;
/// 视频窗口
@property (nonatomic, strong, readonly) UIView *playerView;
/// 视频背景图，默认显示模式 UIViewContentModeCenter
@property (nonatomic, strong) UIImageView *backgroundImgView;
/// 播放器是否可播放的标志位
@property (nonatomic, assign, readonly) BOOL playable;
/// 播放器是否正在播放暖场广告
@property (nonatomic, assign, readonly) BOOL playingAD;
/// 播放器是否显示视频视图
@property (nonatomic, assign, readonly) BOOL showVideoView;

/// agora user 信息(SEI)
@property (nonatomic, readonly) long curFrameAgoraUserTC;
/// 视频缓存时长
@property (nonatomic, readonly) int64_t videoCacheDuration;
/// TCP 网络下载速率
@property (nonatomic, readonly) int64_t originalTcpSpeed;
/// TCP 网络下载速率（格式化字符串）
@property (nonatomic, readonly) NSString *tcpSpeed;

/**
 设置进入后台后暂停视频（主视频）
 回到前台，不会自动恢复播放，需重新调用播放方法。
 如果开启后台播放模式，同时需要在 Target 应用的 Capability 中开启 “Background Modes”  “Audio, AirPlay, and Picture in Picture”
 */
@property (nonatomic, assign) BOOL pauseInBackground;

/**
 设置进入后台后暂停视频（暖场视频或片尾广告）
 回到前台，自动恢复播放。
 */
@property (nonatomic, assign) BOOL pauseADInBackground;

/// 清空所有播放器资源
- (void)clearAllPlayer;

/// 外部横竖屏旋转动画时调用，改变播放器窗口Frame
- (void)setFrame:(CGRect)rect;

/// 暂停
- (void)pause;

@end

@protocol PLVPlayerControllerDelegate <NSObject>

@optional
/// 刷新皮肤的多码率和多线路的按钮
- (void)playerController:(PLVPlayerController *)playerController codeRateItems:(NSMutableArray *)codeRateItems codeRate:(NSString *)codeRate lines:(NSUInteger)lines line:(NSInteger)line;

/// 加载主播放器失败（原因：1.网络请求失败；2.如果是直播，且该频道设置了限制条件）
- (void)playerController:(PLVPlayerController *)playerController loadMainPlayerFailure:(NSString *)message;

/// 播放器状态改变的Message消息回调
- (void)playerController:(PLVPlayerController *)playerController showMessage:(NSString *)message;

/// 改变视频所在窗口（主屏或副屏）的底色
- (void)changePlayerScreenBackgroundColor:(PLVPlayerController *)playerController;

/// 广告播放器已准备好开始播放暖场广告
- (void)playerController:(PLVPlayerController *)playerController subPlaybackIsPreparedToPlay:(NSNotification *)notification;

/// 广告播放器已结束播放暖场广告
- (void)playerController:(PLVPlayerController *)playerController subPlayerDidFinish:(NSNotification *)notification;

/// 主播放器已准备好开始播放正片
- (void)playerController:(PLVPlayerController *)playerController mainPlaybackIsPreparedToPlay:(NSNotification *)notification;

/// 主播放器加载状态有改变
- (void)playerController:(PLVPlayerController *)playerController mainPlayerLoadStateDidChange:(NSNotification *)notification;

/// 主播放器播放播放状态有改变
- (void)playerController:(PLVPlayerController *)playerController mainPlayerPlaybackStateDidChange:(NSNotification *)notification;

/// 主播放器已结束播放
- (void)playerController:(PLVPlayerController *)playerController mainPlayerPlaybackDidFinish:(NSNotification *)notification;

/// 主播放器Seek完成
- (void)playerController:(PLVPlayerController *)playerController mainPlayerDidSeekComplete:(NSNotification *)notification;

/// 主播放器精准Seek完成
- (void)playerController:(PLVPlayerController *)playerController mainPlayerAccurateSeekComplete:(NSNotification *)notification;

/// 主播器解析SEI信息回调
- (void)playerController:(PLVPlayerController *)playerController mainPlayerSeiDidChange:(long)timeStamp;

@end
