//
//  PLVConfig.h
//  PolyvFoundationSDK
//
//  Created by zykhbl on 2018/9/6.
//  Copyright © 2018年 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PLVLogLevel) {
    PLVLogLevelNoLog = 0,
    PLVLogLevelDebug = 1,
    PLVLogLevelInfo  = 2,
    PLVLogLevelError = 3
};

@protocol PLVConfig <NSObject>

/// 播放器名字
@property (nonatomic, strong) NSString *playerName;
/// 播放器版本
@property (nonatomic, strong) NSString *playerVersion;
/// 播放器Id
@property (nonatomic, strong) NSString *playerId;
/// userAgent
@property (nonatomic, strong) NSString *userAgent;
/// polyv 云直播账号ID
@property (nonatomic, strong) NSString *userId;
/// polyv 云直播应用ID
@property (nonatomic, strong) NSString *appId;
/// 当前房间号/频道号
@property (nonatomic, strong) NSString *channelId;
/// 回放视频的vid
@property (nonatomic, strong) NSString *vodId;
/// polyv 云直播应用密匙
@property (nonatomic, strong) NSString *appSecret;
/// 日志级别
@property (nonatomic, assign) PLVLogLevel logLevel;

/// 单例方法
+ (instancetype)sharedInstance;

/// 设置播放器版本信息
+ (void)setPlayerVersion:(NSString *)playerVersion;

/// 设置Polyv Live SDK LOG等级
+ (void)setLogLevel:(PLVLogLevel)logLevel;

/// 重置播放器 Id
+ (void)resetPlayerId;

+ (NSString *)playerVersion;

+ (NSString *)playerName;

+ (NSString *)userAgent;

+ (PLVLogLevel)logLevel;

@end
