//
//  PLVBLinkMicManager.h
//  PolyvBusinessSDK
//
//  Created by Lincal on 2020/3/20.
//  Copyright © 2020 polyv. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 网络状态
typedef NS_ENUM(NSInteger, PLVBLinkMicNetworkQuality) {
    PLVBLinkMicNetworkQualityUnknown = 0,// 未知
    PLVBLinkMicNetworkQualityGood = 1,   // 好
    PLVBLinkMicNetworkQualityFine = 2,   // 良好
    PLVBLinkMicNetworkQualityBad = 3,    // 差
    PLVBLinkMicNetworkQualityDown = 4,   // 离线
};

/// rtc服务连接状态
typedef NS_ENUM(NSInteger, PLVBLinkMicConnectionStateType) {
    PLVBLinkMicConnectionStateDisconnected = 1, // 已断开
    PLVBLinkMicConnectionStateConnecting = 2,   // 连接中
    PLVBLinkMicConnectionStateConnected = 3,    // 已连接
    PLVBLinkMicConnectionStateReconnecting = 4, // 重连中
    PLVBLinkMicConnectionStateFailed = 5,       // 连接失败
};

/// 流画面比例
typedef NS_ENUM(NSInteger, PLVBLinkMicStreamScale) {
    PLVBLinkMicStreamScale16_9 = 0,  // 16:9
    PLVBLinkMicStreamScale4_3 = 1,   // 4:3
};

/// 流分辨率
typedef NS_ENUM(NSInteger, PLVBLinkMicStreamQuality) {
    PLVBLinkMicStreamQuality180P = 0, // 180p（标清）
    PLVBLinkMicStreamQuality360P = 4, // 360p（高清）
    PLVBLinkMicStreamQuality720P = 8, // 720p（超清）
};

/// 用户角色
typedef NS_ENUM(NSInteger, PLVBLinkMicRoleType) {
    PLVBLinkMicRoleBroadcaster = 1, // 主播
    PLVBLinkMicRoleAudience = 2,    // 观众
};

/// RTC类型
typedef NS_ENUM(NSInteger, PLVBLinkMicRTCType) {
    PLVBLinkMicRTCType_AG = 1, // AG
    PLVBLinkMicRTCType_UC = 2, // UC
    PLVBLinkMicRTCType_ZE = 3, // ZE
};

@protocol PLVBLinkMicManagerDelegate;

/// 连麦管理器 (连麦、cdn推流)
@interface PLVBLinkMicManager : NSObject

/// 代理
@property (nonatomic, weak) id <PLVBLinkMicManagerDelegate> delegate;

#pragma mark 账户相关
@property (nonatomic, copy) NSString * plvAppId;
@property (nonatomic, copy) NSString * plvAppSecret;
/// rtc类型
@property (nonatomic, assign) PLVBLinkMicRTCType rtcType;

#pragma mark 频道相关
/// 频道号ID(房间号)
@property (nonatomic, copy, readonly) NSString * channelId;
/// 本地用户(自己)连麦ID
@property (nonatomic, copy, readonly) NSString * userLinkMicId;

#pragma mark 状态相关
/// 是否已加入rtc频道
@property (nonatomic, assign, readonly) BOOL hadJoinedRTC;
/// 当前网络状态
@property (nonatomic, assign, readonly) PLVBLinkMicNetworkQuality networkQuality;
/// 当前rtc频道连接状态
@property (nonatomic, assign, readonly) PLVBLinkMicConnectionStateType connectionState;
/// 当前用户角色
@property (nonatomic, assign, readonly) PLVBLinkMicRoleType roleType;
/// 是否正在推流至cdn
@property (nonatomic, assign, readonly) BOOL streamPublishing;

/// 本地视频流(摄像头) 是否关闭 (通过 [openCamera:] 方法开关)
@property (nonatomic, assign, readonly) BOOL muteLocalVideo;
/// 本地音频流(麦克风) 是否关闭 (通过 [changeVolume:] 方法开关)
@property (nonatomic, assign, readonly) BOOL muteLocalAudio;
/// 摄像头是否前置 (YES: 前置 NO: 后置，通过 [switchCamera:] 方法调整)
@property (nonatomic, assign, readonly) BOOL frontCamera;
/// 麦克风音量大小 (通过 [changeVolume:] 方法调整)
@property (nonatomic, assign, readonly) CGFloat volume;

#pragma mark 推流相关
/// 推流画面比例
@property (nonatomic, assign) PLVBLinkMicStreamScale streamScale;
/// 推流分辨率
@property (nonatomic, assign) PLVBLinkMicStreamQuality streamQuality;

@property (nonatomic, assign, readonly) NSUInteger videoCDNWidth;
@property (nonatomic, assign, readonly) NSUInteger videoCDNHeight;

/// 创建连麦管理器
///
/// 由外部根据频道信息获取到rtc类型值，并在调用此方法时传入；若传入的rtcType值无效，将创建失败，并返回 nil。
///
/// @param rtcType rtc类型值
+ (instancetype)linkMicManagerWithRTCType:(NSString *)rtcType;

/// 更新连麦Token
///
/// 加入RTC连麦频道前，必须调用此方法更新连麦Token。调用该方法，将立刻收到返回的 int 值，小于0表示更新失败 (失败原因可见打印)，此时不允许加入RTC连麦频道，调用 [joinRtcChannelWithChannelId:] 将失败；等于0表示成功。
///
/// @param linkMicStr 连麦信息字符串
- (int)updateLinkMicTokenWithStr:(NSString *)linkMicStr;

/// 加入频道
- (int)joinRtcChannelWithChannelId:(NSString *)channelId userLinkMicId:(NSString *)userLinkMicId;
/// 退出频道
- (int)leaveRtcChannel;

- (void)addRTCCanvasAtSuperView:(UIView *)superView uid:(NSString *)uid;
/// 切换用户角色
- (int)setUserRoleTo:(PLVBLinkMicRoleType)roleType;

/// 切换前后摄像头（YES-前置 NO-后置）
- (int)switchCamera:(BOOL)front;
/// 开关摄像头（YES-开启 NO-关闭）
- (void)openCamera:(BOOL)openCamera completion:(nullable void (^)(int result))completion;

- (int)startPreview;
- (int)stopPreview;

- (int)disableVideo;
- (int)enableVideo;

- (int)enableLocalVideo:(BOOL)enabled;
- (int)muteLocalVideoStream:(BOOL)mute;

/// 修改麦克风音量（0 表示静音；范围 0~100）
- (int)changeVolume:(CGFloat)volume;

- (int)disableAudio;
- (int)enableAudio;

- (int)enableLocalAudio:(BOOL)enabled;
- (int)muteLocalAudioStream:(BOOL)mute;

/// 配置视频编码参数
- (void)setupVideoEncoderConfiguration;
/// 添加推流地址
- (int)addPublishStreamUrl:(NSString *)streamUrl transcodingEnabled:(BOOL)transcodingEnabled;
/// 移除推流地址
- (int)removePublishStreamUrl:(NSString *)streamUrl;
/// 配置推流转码参数
- (void)setupLiveTranscoding;
/// 配置混流参数
- (int)setupLiveTranscodingUser;
/// 配置混流额外信息
- (int)setupLiveTranscodingExtraInfo:(NSString *)extroInfo;
/// 配置推流占位图
- (BOOL)setupLiveBackgroundImage;

@end

@protocol PLVBLinkMicManagerDelegate <NSObject>

@optional

#pragma mark 本地用户(自己) 事件回调
/// 本地用户 加入RTC频道
///
/// @param manager 连麦管理器
/// @param channelId 加入频道ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager joinRTCChannelComplete:(NSString * _Nonnull)channelId uid:(NSString *)uid;

/// 本地用户 退出RTC频道
///
/// @param manager 连麦管理器
/// @param channelId 退出频道ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager leaveRTCChannelComplete:(NSString * _Nonnull)channelId;

/// 本地用户 连麦发生错误（若自动退出RTC频道，则会触发 [leaveRTCChannelComplete:] 回调）
///
/// @param manager 连麦管理器
/// @param errorCode 错误码
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didOccurError:(NSInteger)errorCode;

/// 本地RTC连接状态改变
///
/// @param manager 连麦管理器
/// @param connectionState 当前rtc连接状态
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager rtcConnectionStateDidChanged:(PLVBLinkMicConnectionStateType)connectionState;

/// 本地用户 连麦Token过期
///
/// @param manager 连麦管理器
- (void)plvbLinkMicManagerTokenExpires:(PLVBLinkMicManager * _Nonnull)manager;

#pragma mark 本地设备事件回调
/// 网络状态改变
///
/// @param manager 连麦管理器
/// @param networkQuality 当前网络状态值
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager networkQuality:(PLVBLinkMicNetworkQuality)networkQuality;

/// 本地摄像头准备就绪
///
/// @param manager 连麦管理器
- (void)plvbLinkMicManagerCameraDidReady:(PLVBLinkMicManager * _Nonnull)manager;

/// 本地视频流（摄像头）关闭回调
///
/// 调用openCamera:completion:方法将触发此回调；仅在前者方法调用‘成功’后，此回调才被调用，并告知最终本地视频流的开关状态；
///
/// @param manager 连麦管理器
/// @param videoMuted 本地视频流是否关闭
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didLocalVideoMuted:(BOOL)videoMuted;

/// 声音监测回调
///
/// @param manager 连麦管理器
/// @param voiceAudible 是否接收到本地可听得见的声音（以一般讲话音量为准）
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager receivedLocalAudibleVoice:(BOOL)voiceAudible;

#pragma mark 远端用户(别人) 事件回调
/// 远端用户 加入RTC频道
///
/// @param manager 连麦管理器
/// @param uid 远端用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didJoinedOfUid:(NSString *)uid;

/// 远端用户 退出RTC频道
///
/// @param manager 连麦管理器
/// @param uid 远端用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didOfflineOfUid:(NSString *)uid;

/// 远端用户 音频流禁止状态更新回调
///
/// @param manager 连麦管理器
/// @param muted 音频流是否禁止
/// @param uid 禁止状态更新的用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didAudioMuted:(BOOL)muted byUid:(NSString *)uid;

/// 远端用户 视频流禁止状态更新回调
///
/// @param manager 连麦管理器
/// @param muted 视频流是否禁止
/// @param uid 禁止状态更新的用户连麦ID
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager didVideoMuted:(BOOL)muted byUid:(NSString *)uid;

#pragma mark 通用(自己、别人) 事件回调
/// 全部连麦成员的音频音量 回调
///
/// @note 该回调的时间间隔约为 100ms~300ms
///
/// @param manager 连麦管理器
/// @param volumeDict 连麦成员音量字典 (key:用户连麦ID，value:对应的流的音量值；value取值范围为 0.0 ~ 1.0)
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager reportAudioVolumeOfSpeakers:(NSDictionary<NSString *, NSNumber *> * _Nonnull)volumeDict;

#pragma mark 推流事件回调
/// 推流到CDN结果
///
/// @param manager 连麦管理器
/// @param sucess 推流结果
- (void)plvbLinkMicManager:(PLVBLinkMicManager * _Nonnull)manager streamPublishedResult:(BOOL)sucess;

/// CDN推流断流回调
///
/// @param manager 连麦管理器
- (void)plvbLinkMicManagerStreamUnpublished:(PLVBLinkMicManager * _Nonnull)manager;

@end

NS_ASSUME_NONNULL_END
