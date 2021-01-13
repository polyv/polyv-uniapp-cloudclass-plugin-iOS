//
//  PLVFConsoleLogger.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2020/2/20.
//  Copyright © 2020 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, PLVFConsoleLogType) {
    PLVFConsoleLogTypeERROR     = 1 << 0,
    PLVFConsoleLogTypeWARN      = 1 << 1,
    PLVFConsoleLogTypeDEBUG     = 1 << 2,
    PLVFConsoleLogTypeINFO      = 1 << 3
};

typedef NS_ENUM(NSUInteger, PLVFConsoleLogLevel) {
    PLVFConsoleLogLevelOFF      = 0,
    PLVFConsoleLogLevelERROR    = PLVFConsoleLogTypeERROR,
    PLVFConsoleLogLevelWARN     = PLVFConsoleLogTypeERROR  | PLVFConsoleLogTypeWARN,
    PLVFConsoleLogLevelDEBUG    = PLVFConsoleLogTypeINFO   | PLVFConsoleLogTypeDEBUG,
    PLVFConsoleLogLevelINFO     = PLVFConsoleLogTypeINFO,
    PLVFConsoleLogLevelALL      = 0xF
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFConsoleLogger : NSObject

@property (nonatomic, assign) PLVFConsoleLogLevel logLevel;

+ (instancetype)defaultLogger;

- (void)logWithModule:(NSString * _Nullable)module type:(PLVFConsoleLogType)type format:(NSString *)frmt, ...;

@end

#define PLVFLOG_ERROR( frmt, ...) PLVFLOG( nil, PLVFConsoleLogTypeERROR , frmt , ## __VA_ARGS__)
#define PLVFLOG_WARN( frmt, ...) PLVFLOG( nil, PLVFConsoleLogTypeWARN , frmt , ## __VA_ARGS__)
#define PLVFLOG_DEBUG( frmt, ...) PLVFLOG( nil, PLVFConsoleLogTypeDEBUG , frmt , ## __VA_ARGS__)
#define PLVFLOG_INFO( frmt, ...) PLVFLOG( nil, PLVFConsoleLogTypeINFO , frmt , ## __VA_ARGS__)

#define PLVF_NORMAL_LOG_ERROR( module, frmt, ...) PLVFLOG( module, PLVFConsoleLogTypeERROR , frmt , ## __VA_ARGS__)
#define PLVF_NORMAL_LOG_WARN( module, frmt, ...) PLVFLOG( module, PLVFConsoleLogTypeWARN , frmt , ## __VA_ARGS__)
#define PLVF_NORMAL_LOG_DEBUG( module, frmt, ...) PLVFLOG( module, PLVFConsoleLogTypeDEBUG , frmt , ## __VA_ARGS__)
#define PLVF_NORMAL_LOG_INFO( module, frmt, ...) PLVFLOG( module, PLVFConsoleLogTypeINFO , frmt , ## __VA_ARGS__)

#define PLVFLOG(module, logType, frmt, ...) \
{ \
    [[PLVFConsoleLogger defaultLogger] logWithModule : module \
                                        type : logType \
                                          format : (frmt), ## __VA_ARGS__]; \
}

NS_ASSUME_NONNULL_END
