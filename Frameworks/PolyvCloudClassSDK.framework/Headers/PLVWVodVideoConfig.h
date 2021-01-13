//
//  PLVWVodVideoConfig.h
//  PolyvCloudClassSDK
//
//  Created by ftao on 2020/4/21.
//  Copyright © 2020 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
点播视频配置文件
*/
@interface PLVWVodVideoConfig : NSObject

/// 统计后台用户Id (sid)
@property (nonatomic, copy) NSString *viewerId;
/// 统计后台用户名称 (param2)
@property (nonatomic, copy) NSString *viewerName;

/// 统计后台自定义参数1
@property (nonatomic, copy) NSString *param1;
/// 统计后台自定义参数3
@property (nonatomic, copy) NSString *param3;
/// 统计后台自定义参数4
@property (nonatomic, copy) NSString *param4;
/// 统计后台自定义参数5
@property (nonatomic, copy) NSString *param5;


+ (instancetype)sharedInstance;

/// 设置统计后台参数
/// @param viewerId 用户Id
/// @param viewerName 用户名称
+ (void)setViewLogViewerId:(NSString *)viewerId viewerName:(NSString *)viewerName;

/// 设置统计后台自定义参数
/// @param param1 统计后台自定义参数1
/// @param param3 统计后台自定义参数3
/// @param param4 统计后台自定义参数4
/// @param param5 统计后台自定义参数5
+ (void)setViewLogParam:(NSString *)param1 param3:(NSString *)param3 param4:(NSString *)param4 param5:(NSString *)param5;

@end

NS_ASSUME_NONNULL_END
