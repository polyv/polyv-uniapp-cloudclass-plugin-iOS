//
//  PLVLinkMicManager.h
//  PolyvCloudClassSDK
//
//  Created by Lincal on 2020/2/3.
//  Copyright © 2020 polyv. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PolyvBusinessSDK/PLVSocketObject.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PLVLinkMicSceneType) {
    PLVLinkMicSceneTypeLive       = 1,/// 旧普通直播连麦
    PLVLinkMicSceneTypeNormalLive = 2,/// 新普通直播连麦
    PLVLinkMicSceneTypeCloudClass = 3 /// 云课堂连麦
};

typedef NS_ENUM(NSInteger, PLVLinkMicRoleType) {
    PLVLinkMicRoleBroadcaster = 1, /// 主播
    PLVLinkMicRoleAudience = 2, /// 观众
};

@class PLVLinkMicManager;

@protocol PLVLinkMicManagerDelegate <NSObject>

@optional

#pragma mark 本地用户事件回调
/// 本地用户加入RTC频道回调
/// @param manager 连麦管理器
/// @param channelID 加入频道ID
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager joinRTCChannelComplete:(NSString * _Nonnull)channelID uid:(NSUInteger)uid;

/// 本地用户退出RTC频道回调
/// @param manager 连麦管理器
/// @param channelID 退出频道ID
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager leaveRTCChannelComplete:(NSString * _Nonnull)channelID;

/// 本地用户连麦错误发生回调（若自动退出RTC频道，则会触发 [leaveRTCChannelComplete:] 回调）
/// @param manager 连麦管理器
/// @param errorCode 错误码
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager didOccurError:(NSInteger)errorCode;

#pragma mark 远端用户事件回调
/// 远端用户加入RTC频道回调
/// @param manager 连麦管理器
/// @param uid 远端用户id
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager didJoinedOfUid:(NSUInteger)uid;

/// 远端用户退出RTC频道回调
/// @param manager 连麦管理器
/// @param uid 远端用户id
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager didOfflineOfUid:(NSUInteger)uid;

/// 远端用户音频流禁止状态改变回调
/// @param manager 连麦管理器
/// @param muted 音频流是否禁止
/// @param uid 禁止状态改变的用户id
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager didAudioMuted:(BOOL)muted byUid:(NSUInteger)uid;

/// 远端用户视频流禁止状态改变回调
/// @param manager 连麦管理器
/// @param muted 视频流是否禁止
/// @param uid 禁止状态改变的用户id
- (void)plvLinkMicManager:(PLVLinkMicManager * _Nonnull)manager didVideoMuted:(BOOL)muted byUid:(NSUInteger)uid;

@end

@interface PLVLinkMicManager : NSObject

/// 频道号ID（房间号）
@property (nonatomic, copy, readonly) NSString * channelId;
/// 本地用户连麦ID
@property (nonatomic, copy, readonly) NSString * userLinkMicId;
/// 是否已加入rtc频道
@property (nonatomic, assign, readonly) BOOL hadJoinedRTC;

/// 连麦类型（普通直播连麦，或云课堂连麦）
@property (nonatomic, assign) PLVLinkMicSceneType linkMicType;
/// 连麦类型（YES：声音；NO：视频）
@property (nonatomic, assign) BOOL linkMicOnAudio;
/// 参与者是否允许上麦
@property (nonatomic, assign) BOOL viewerAllow;

/// 代理
@property (nonatomic, weak) id delegate;
/// 是否参与者
@property (nonatomic, assign) BOOL viewer;

/// 加入连麦频道
- (int)joinRtcChannelWithChannelId:(NSString *)channelId userLinkMicId:(NSString *)userLinkMicId;
/// 退出连麦频道
- (void)leaveRtcChannel;

/// 角色切换
- (void)switchClientRoleTo:(PLVLinkMicRoleType)role;
/// 添加RTC画面
- (void)addRTCCanvasAtSuperView:(UIView *)superView uid:(NSUInteger)uid remoteUser:(BOOL)remoteUser;
/// 设备控制
- (int)switchCamera;
- (int)enableLocalAudio:(BOOL)enabled;
- (int)muteLocalVideoStream:(BOOL)mute;
- (int)muteLocalAudioStream:(BOOL)mute;

@end

NS_ASSUME_NONNULL_END
