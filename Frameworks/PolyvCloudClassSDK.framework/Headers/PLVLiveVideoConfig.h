//
//  PLVLiveVideoConfig.h
//  PolyvCloudClassSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PolyvFoundationSDK/PLVConfig.h>

/**
 直播 SDK 配置文件
 */
@interface PLVLiveVideoConfig : NSObject<PLVConfig>

/// 统计后台用户Id
@property (nonatomic, strong, readonly) NSString *param1;
/// 统计后台观众昵称
@property (nonatomic, strong, readonly) NSString *param2;
/// 统计后台自定义参数4
@property (nonatomic, strong, readonly) NSString *param4;
/// 统计后台自定义参数5
@property (nonatomic, strong, readonly) NSString *param5;

/// 可配置chat私有域名
@property (nonatomic, strong, readonly) NSString *chatDomain;
/// 可配置chatApi私有域名
@property (nonatomic, strong, readonly) NSString *chatApiDomain;

/// 连麦参数信息
@property (nonatomic, strong) NSString *linkMicStr;

/// 弹出相册或相机时不能横竖屏切换
@property (nonatomic, assign) BOOL unableRotate;
/// 互动页面此时是否不能横竖屏切换
@property (nonatomic, assign) BOOL triviaCardUnableRotate;
/// 是否启用 HttpDNS
@property (nonatomic, assign) BOOL enableHttpDNS;
/// 是否启用 IPV6，如果启用，将自动选择IP，取消HttpDNS
@property (nonatomic, assign) BOOL enableIPV6;


/// 视频解码是否硬解，默认 YES
@property (nonatomic, assign) BOOL videoToolBox;

/**
 用户参数：Polyv 后台，云直播->开发设置->身份认证：userId、AppID、AppSecret参数
 */
+ (instancetype)liveConfigWithUserId:(NSString *)userId appId:(NSString *)appId appSecret:(NSString *)appSecret;

/**
 设置统计后台参数，便利生成该类的param1、param2、param4、param5属性
 
 @param param1 统计后台用户Id
 @param param2 统计后台观众昵称
 @param param4 统计后台自定义参数4
 @param param5 统计后台自定义参数5
 */
+ (void)setViewLogParam:(NSString *)param1 param2:(NSString *)param2 param4:(NSString *)param4 param5:(NSString *)param5;

/**
 私有域名配置
 */
+ (void)setPrivateDomainWithData:(NSDictionary *)data;

@end
