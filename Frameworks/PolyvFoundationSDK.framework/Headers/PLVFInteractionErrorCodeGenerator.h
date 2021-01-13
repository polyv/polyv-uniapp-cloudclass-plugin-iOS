//
//  PLVFInteractionErrorCodeGenerator.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2020/1/13.
//  Copyright © 2020 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFInteractionErrorCode){
    /* web 相关错误 */
    PLVFInteractionErrorCodeWebLoadFail = 001,
    
    /* http 接口请求错误 */
    /// 放弃领奖接口
    PLVFInteractionErrorCodeGiveUpLottery_ParameterError = 101,
    PLVFInteractionErrorCodeGiveUpLottery_CodeError = 102,
    PLVFInteractionErrorCodeGiveUpLottery_DataError = 103,
    /// 提交中奖信息接口
    PLVFInteractionErrorCodePostLottery_ParameterError = 104,
    PLVFInteractionErrorCodePostLottery_CodeError = 105,
    PLVFInteractionErrorCodePostLottery_DataError = 106,
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFInteractionErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFInteractionErrorCode)error;

+ (NSString *)errorDescription:(PLVFInteractionErrorCode)error;

@end

NS_ASSUME_NONNULL_END
