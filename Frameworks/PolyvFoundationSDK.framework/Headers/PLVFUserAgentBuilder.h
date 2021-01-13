//
//  PLVFUserAgentBuilder.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/11/29.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PLVFProductType) {
    PLVFProductTypeVod = 1,              /// 点播
    PLVFProductTypeLive = 2,             /// 直播
    PLVFProductTypeRtmp = 3,             /// 旧推流
    PLVFProductTypeCloudClass = 4,       /// 云课堂
    PLVFProductTypeShortVideo = 5,       /// 短视频
    PLVFProductTypeStreamer = 6,         /// 手机开播
    PLVFProductTypeIPadStreamer = 7,     /// iPad开播
};

typedef NS_ENUM(NSInteger, PLVFFrameworkType) {
    PLVFFrameworkOrigin = 1,      /// 原生
    PLVFFrameworkRN = 2,          /// React Native
    PLVFFrameworkAPICloud = 3,    /// APICloud
};

@interface PLVFUserAgentBuilder : NSObject

/// 设备类型-标识：phone、pad、tv
@property (nonatomic, copy, readonly) NSString *deviceType;

/// 技术框架平台：原生-origin、React Native-RN、APICloud-APICloud
@property (nonatomic, copy, readonly) NSString *framework;

/// 产品字符串标识：点播-vod、直播-live、旧的推流-rtmp、云课堂-cloudClass、短视频-shortVideo、手机开播-cloudClassStream、iPad开播-cloudClassIPadStream
@property (nonatomic, copy, readonly) NSString *project;

+ (instancetype)sharedBuilder;

/**
初始化配置
@param productType 产品类型
@param sdkVersion sdk 版本号+发版日期
*/
- (void)configWithProductType:(PLVFProductType)productType sdkVersion:(NSString *)sdkVersion;

/// 如不调用，默认是原生技术框架
- (void)changeFramework:(PLVFFrameworkType)frameworkType;

/// 返回程序版本号，譬如 0.1.0+20190322/0110101
- (NSString *)formatVersion;

/// 返回设备名称和设备系统版本号，譬如 iPhone5,2 iOS/10_1
+ (NSString *)getDeviceNameAndVersion;

/// 返回所有设备相关信息，譬如 iPhone5,2 iOS/10_1 CFNetwork/978.0.7 Darwin/19.2.0
+ (NSString *)getDeviceAllInfo;


@end

NS_ASSUME_NONNULL_END
