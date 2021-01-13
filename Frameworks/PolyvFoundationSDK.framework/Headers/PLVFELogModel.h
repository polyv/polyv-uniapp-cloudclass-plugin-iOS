//
//  PLVFELogModel.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/11/28.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFLogModel.h"

NS_ASSUME_NONNULL_BEGIN

@class PLVELogLogModel, PLVELogLogFileModel, PLVELogLogFilePlayerPramaModel;

@interface PLVFELogModel : PLVFLogModel

/// 点播独有属性
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *secretkey;

/// 直播、推流独有属性
@property (nonatomic, copy) NSString *channelId;
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *appSecret;

/// json 格式字符串，需要做 URLEncoder
@property (nonatomic, strong) PLVELogLogModel *log;

/// log 模型的 json 数组
@property (nonatomic, strong) NSArray<PLVELogLogModel *> *logs;

@end

@interface PLVELogLogModel : NSObject

/// 直播：频道 ID
@property (nonatomic, copy) NSString *channelId2;

/// 点播：视频 ID
@property (nonatomic, copy) NSString *videoId;

/// 用户 ID
@property (nonatomic, copy) NSString *userId2;

/// 播放 ID
@property (nonatomic, copy) NSString *playId;

/// 非错误事件类型，统一使用不缩写驼峰式命名
@property (nonatomic, copy) NSString *event;

/// 设备类型-标识：phone、pad、tv
@property (nonatomic, copy) NSString *deviceType;

/// 技术平台-标识：原生-origen、RN、APICloud
@property (nonatomic, copy) NSString *framework;

/// 模块标识，错误码规范中的模块标识英文名
@property (nonatomic, copy) NSString *module;

/// 格式为 "版本号+版本发布日期/{端来源}{设备类型}{技术框架平台}{产品}"
/// 譬如 2.7.2+20190322/0110101
@property (nonatomic, copy) NSString *version2;

/// 记录这条日志的毫秒单位的时间戳，记录日志的时间和发送日志到服务器的时间有时会不一致，比如弱网重发
@property (nonatomic, copy) NSString *time;

/// 平台：Android、iOS、H5、Flash、PC
@property (nonatomic, copy) NSString *platform2;

// 产品标识：点播-vod、直播-live、旧的推流-rtmp、云课堂-cloudClass、短视频-shortVideo、手机开播-cloudClassStream、iPad开播-cloudClassIPadStream
@property (nonatomic, copy) NSString *project;

/// json 格式字符串
@property (nonatomic, strong) PLVELogLogFileModel *logFile;

#pragma mark 非必选字段

/// 学员 ID
@property (nonatomic, copy) NSString *viewerId;

/// 错误码，如果这条日志是错误日志，该字段必须设置值
@property (nonatomic, copy) NSString *errorCode;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end

@interface PLVELogLogFileModel : NSObject

#pragma mark 非必选字段

/// app 日志，系统日志
@property (nonatomic, copy) NSString *logFile;

/// 普通信息，自定义的信息
@property (nonatomic, copy) NSString *infomation;

/// 异常信息，程序异常，出错堆栈信息
@property (nonatomic, copy) NSString *exception;

/// Android & iOS 端 ijkplayer 播放器参数。json 格式字符串，内部是一个 playerParam 列表，见 playerParam 字段格式
@property (nonatomic, strong) NSArray<PLVELogLogFilePlayerPramaModel *> *playerParam ;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end

@interface PLVELogLogFilePlayerPramaModel : NSObject

@property (nonatomic, copy) NSString *type;  // 参数类型
@property (nonatomic, copy) NSString *name;  // 参数名称
@property (nonatomic, copy) NSString *value; // 参数值

- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
