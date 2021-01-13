//
//  PLVPlayerControllerProtocol.h
//  PolyvCloudClassSDK
//
//  Created by zykhbl on 2018/9/18.
//  Copyright © 2018年 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PLVPlayerControllerProtocol <NSObject>

/// 当前播放时间(点播)
@property(nonatomic, readonly) NSTimeInterval currentPlaybackTime;
/// 视频总时长(点播)
@property(nonatomic, readonly) NSTimeInterval duration;

/// 用户观看时长(不包含连麦)
@property (nonatomic, readonly) NSInteger watchDuration;
/// 用户观看总时长(包含连麦)
@property (nonatomic, readonly) NSInteger totalWatchDuration;
/// 用户停留时长
@property (nonatomic, readonly) NSInteger stayDuration;

/**
 清空所有播放器和定时器资源
 退出登录时，在UIViewController dealloc前先手动调用
 */
- (void)clearPlayersAndTimers;

@end

/// 音频模式视图协议
@protocol PLVPlayerAudioModeViewProtocol <NSObject>

/// 显示/隐藏音频模式视图
- (void)appear:(BOOL)show;

@end
