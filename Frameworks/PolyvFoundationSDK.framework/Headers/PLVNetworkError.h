//
//  PLVNetworkError.h
//  PolyvFoundationSDK
//
//  Created by zykhbl on 2018/8/6.
//  Copyright © 2018年 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PLVNetworkErrorCode) {
    PLVNetworkErrorCodeParamsInvalid            = -10000, //参数无效/非法
    PLVNetworkErrorCodeAuthParamsInvalid        = -10001, //保利威授权信息无效
    PLVNetworkErrorCodeResponseFail             = -10010, //服务器请求失败异常，响应非200
    PLVNetworkErrorCodeJsonDecodeFail           = -10020, //JSON解析失败
    PLVNetworkErrorCodeEncodeJsonDecodeFail     = -10021, //加密JSON解析失败
    PLVNetworkErrorCodeDecodeFail               = -10022, //解码失败（异常）
    PLVNetworkErrorCodeLoginFail                = -10030, //登录失败（登录接口）
    PLVNetworkErrorCodeSettingFail              = -10040, //设置失败
    PLVNetworkErrorCodeRequestFail              = -10050, //请求失败（解析JSON数据中code非200）
};

@interface PLVNetworkError : NSError

+ (NSString *)descWithCode:(NSInteger)code;

@end
