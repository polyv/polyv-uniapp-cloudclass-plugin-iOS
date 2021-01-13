//
//  PLVLivePlayerController.h
//  PolyvCloudClassSDK
//
//  Created by zykhbl on 2018/7/30.
//  Copyright © 2018年 polyv. All rights reserved.
//

#import "PLVPlayerController.h"
#import "PLVPlayerControllerProtocol.h"
#import "PLVLiveDefine.h"
#import "PLVLiveVideoChannel.h"

@protocol PLVLivePlayerControllerDelegate;

// 直播播放器
@interface PLVLivePlayerController : PLVPlayerController <PLVPlayerControllerProtocol>

/// 当前频道
@property (nonatomic, strong, readonly) PLVLiveVideoChannel *channel;
/// 当推流端的摄像头是否已经关闭，由外层Demo会根据接收到Socket信息设置该值
@property (nonatomic, assign) BOOL cameraClosed;
/// 连麦状态时，刷新或定时器不能自动打开视频
@property (atomic, assign) BOOL linkMic;
/// 当前频道是否支持音频模式
@property (nonatomic, assign, readonly) BOOL supportAudioMode;
/// 当前是否为音频模式
@property (nonatomic, assign, readonly) BOOL audioMode;
/// 是否开启追帧，默认 NO
@property (nonatomic, assign) BOOL chaseFrame;
/// 音频模式视图，需遵循协议并实现方法，SDK将在适当时机调用协议方法
@property (nonatomic, strong) UIView <PLVPlayerAudioModeViewProtocol>* audioModeDisplayView;

/// 初始化直播播放器
- (instancetype)initWithChannelId:(NSString *)channelId userId:(NSString *)userId playAD:(BOOL)playAD displayView:(UIView *)displayView delegate:(id)delegate;

/// 加载主播放器（切换线路或码率，重连或刷新的时候调用）
- (void)loadChannelWithLineIndex:(NSInteger)lineIndex codeRate:(NSString *)codeRate completion:(void (^)(void))completion failure:(void (^)(NSString *))failure;

/// 加载主播放器（切换线路）
- (void)loadChannelAtLineIndex:(NSUInteger)lineIndex completion:(void (^)(void))completion failure:(void (^)(NSString *message))failure;

/// 切换为音频模式，切换后需重新调用loadChannel
- (void)switchAudioMode:(BOOL)audioMode;

/// 正在直播中
- (BOOL)playing;

/// 普通直播，连麦时，CDN 直播流静音
- (void)mute;

/// 普通直播，取消连麦时，取消 CDN 直播流静音
- (void)cancelMute;

/**
 获取当前直播的seesionId
 
 @return 返回值有可能为 nil，Demo层需要做判断
 */
- (NSString *)currentChannelSessionId;

/**
 加载直播频道信息

 @param userId 用户ID
 @param channelId 频道ID
 @param completion 加载完成
 @param failure 加载失败
 */
+ (void)loadLiveVideoChannelWithUserId:(NSString *)userId channelId:(NSUInteger)channelId completion:(void (^)(PLVLiveVideoChannel *channel))completion failure:(void (^)(NSError *error))failure;

@end

@protocol PLVLivePlayerControllerDelegate <NSObject>

@optional
/// 定时器查询(每6秒)的直播流状态回调
- (void)livePlayerController:(PLVLivePlayerController *)livePlayer streamState:(PLVLiveStreamState)streamState;

/// 重连播放器回调
- (void)reconnectPlayer:(PLVLivePlayerController *)livePlayer;

/// 频道信息更新
- (void)liveVideoChannelDidUpdate:(PLVLiveVideoChannel *)channel;

/// 直播播放器的播放状态改变
- (void)livePlayerController:(PLVLivePlayerController *)livePlayer playing:(BOOL)playing;

@end
