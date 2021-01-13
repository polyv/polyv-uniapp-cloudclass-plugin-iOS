//
//  PLVFLinkErrorCodeGenerator.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/12/11.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFLinkErrorCode){
    /* http 接口请求错误 */
    /// notify stream 接口
    PLVFLinkErrorCodeNotifyStreamFailed_ParameterError = 101,
    PLVFLinkErrorCodeNotifyStreamFailed_DataError = 103,

    /// 获取连麦Token接口
    PLVFLinkErrorCodeMicAuthFailed_ParameterError = 104,
    PLVFLinkErrorCodeMicAuthFailed_CodeError = 105,
    PLVFLinkErrorCodeMicAuthFailed_DataError = 106,

    /// 获取连麦SessionID接口
    PLVFLinkErrorCodeChannelSessionIDFailed_ParameterError = 107,

    /// 获取推流频道信息接口
    PLVFLinkErrorCodeTeacherLoginFailed_ParameterError = 110,
    PLVFLinkErrorCodeTeacherLoginFailed_DataError = 112,

    /// RTC错误
    PLVFLinkErrorCodeStreamPublishFailed = 401,
    PLVFLinkErrorCodeJoinChannelFailed = 402,
    PLVFLinkErrorCodeAddPublishStreamUrlFailed = 403,
    
    /// 系统错误
    PLVFLinkErrorCodeUnauthorized = 501,
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFLinkErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFLinkErrorCode)error;

+ (NSString *)errorDescription:(PLVFLinkErrorCode)error;

@end

NS_ASSUME_NONNULL_END
