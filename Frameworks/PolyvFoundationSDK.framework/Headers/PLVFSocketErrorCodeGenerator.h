//
//  PLVFSocketErrorCodeGenerator.h
//  PolyvFoundationSDK
//
//  Created by ftao on 2020/1/2.
//  Copyright © 2020 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFSocketErrorCode){
    /* http 接口请求错误 */
    /// 获取 token 接口
    PLVFSocketErrorCodeGetToken_ParameterError = 101,
    PLVFSocketErrorCodeGetToken_CodeError = 102,
    PLVFSocketErrorCodeGetToken_DataError = 103,
    
    /* socket 连接失败 */
    PLVFSocketErrorCodeDisconnect = 501,
    PLVFSocketErrorCodeConnectError = 502,
    PLVFSocketErrorCodeTokenInvail = 503,
    PLVFSocketErrorCodeReconnect = 504,
    
    /* socket 登录失败 */
    PLVFSocketErrorCodeLoginError = 601,
    PLVFSocketErrorCodeLoginAckDataError = 602,
    PLVFSocketErrorCodeLoginAckParamError = 603,
    PLVFSocketErrorCodeLoginAckRoomIdError = 604,
    PLVFSocketErrorCodeLoginAckNicknameError = 605,
    PLVFSocketErrorCodeLoginAckBeKicked = 606,
    PLVFSocketErrorCodeLoginRefuse = 607,
};


NS_ASSUME_NONNULL_BEGIN

@interface PLVFSocketErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFSocketErrorCode)error;

+ (NSString *)errorDescription:(PLVFSocketErrorCode)error;

@end

NS_ASSUME_NONNULL_END
