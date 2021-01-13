//
//  PLVFInitErrorCodeGenerator.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2020/1/15.
//  Copyright © 2020 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFInitErrorCode){
    /* http 接口请求错误 */
    /// 直播登录校验接口
    PLVFInitErrorCodeLiveLogin_ParameterError = 101,
    PLVFInitErrorCodeLiveLogin_CodeError = 102,
    PLVFInitErrorCodeLiveLogin_DataError = 103,
    /// 回放登录校验接口
    PLVFInitErrorCodeVodLogin_ParameterError = 104,
    PLVFInitErrorCodeVodLogin_CodeError = 105,
    PLVFInitErrorCodeVodLogin_DataError = 106,
    /// 直播获取“频道类型和是否正在直播”接口
    PLVFInitErrorCodeLiveInfo_ParameterError = 107,
    PLVFInitErrorCodeLiveInfo_CodeError = 108,
    PLVFInitErrorCodeLiveInfo_DataError = 109,
    /// 回放获取“频道类型”接口
    PLVFInitErrorCodeVodInfo_ParameterError = 110,
    PLVFInitErrorCodeVodInfo_CodeError = 111,
    PLVFInitErrorCodeVodInfo_DataError = 112,
    // 获取频道菜单列表接口
    PLVFInitErrorCodeChannelInfo_ParameterError = 113,
    PLVFInitErrorCodeChannelInfo_CodeError = 114,
    PLVFInitErrorCodeChannelInfo_DataError = 115,
};


NS_ASSUME_NONNULL_BEGIN

@interface PLVFInitErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFInitErrorCode)error;

+ (NSString *)errorDescription:(PLVFInitErrorCode)error;

@end

NS_ASSUME_NONNULL_END
