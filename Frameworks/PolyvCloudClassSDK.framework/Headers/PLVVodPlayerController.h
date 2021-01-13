//
//  PLVVodPlayerController.h
//  PolyvCloudClassSDK
//
//  Created by zykhbl on 2018/8/15.
//  Copyright © 2018年 polyv. All rights reserved.
//

#import "PLVPlayerController.h"
#import "PLVPlayerControllerProtocol.h"

@protocol PLVVodPlayerControllerDelegate;

/// 点播回放播放器
@interface PLVVodPlayerController : PLVPlayerController <PLVPlayerControllerProtocol>

/// 当前video信息
@property (nonatomic, strong, readonly) NSDictionary *vodDict;
/// 其他 viewlog 参数，param1~param5 和 key1~key3 参数值需要 UrlSafeBase64 编码
@property (nonatomic, strong) NSDictionary<NSString *, id> *viewlogExtraParams;
/// 当前播放倍速
@property (nonatomic, assign, readonly) CGFloat curSpeed;

/// 初始化点播播放器
- (instancetype)initWithVodId:(NSString *)vodId displayView:(UIView *)displayView delegate:(id)delegate;

/// 初始化点播播放器
- (instancetype)initWithVodId:(NSString *)vodId vodList:(BOOL)vodList displayView:(UIView *)displayView delegate:(id)delegate;

/// 切换码率
- (void)switchCodeRate:(NSString *)codeRate;

/// 播放
- (void)play;

/// seek快进播放
- (void)seek:(NSTimeInterval)curTime;

/// 倍速播放
- (void)speedRate:(CGFloat)speed;

@end

@protocol PLVVodPlayerControllerDelegate <NSObject>

/// 点播播放器的播放状态改变，刷新皮肤的总播放时间
- (void)vodPlayerController:(PLVVodPlayerController *)vodPlayer duration:(NSTimeInterval)duration playing:(BOOL)playing;

/// 点播播放器的播放状态改变，刷新皮肤的总播放时间，已加载进度，和已播放进度
- (void)vodPlayerController:(PLVVodPlayerController *)vodPlayer dowloadProgress:(CGFloat)dowloadProgress playedProgress:(CGFloat)playedProgress currentPlaybackTime:(NSString *)currentPlaybackTime duration:(NSString *)duration;

@end;
