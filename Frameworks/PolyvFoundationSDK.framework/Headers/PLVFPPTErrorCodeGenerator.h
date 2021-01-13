//
//  PLVFPPTErrorCodeGenerator.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/12/11.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFPPTErrorCode){
    /* http 接口请求错误 */
    // 获取文档列表接口
    PLVFPPTErrorCodeDocumentList_ParameterError = 101,
    PLVFPPTErrorCodeDocumentList_CodeError = 102,
    PLVFPPTErrorCodeDocumentList_DataError = 103,
    // 删除文档接口
    PLVFPPTErrorCodeDocumentDelete_ParameterError = 104,
    PLVFPPTErrorCodeDocumentDelete_CodeError = 105,
    PLVFPPTErrorCodeDocumentDelete_DataError = 106,
    
    /* web 相关异常 */
    PLVFPPTErrorCodeWebLoadFail = 401,
    PLVFPPTErrorCodeJS_ParameterError = 402,
    PLVFPPTErrorCodeJS_DataError = 403,
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFPPTErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFPPTErrorCode)error;

+ (NSString *)errorDescription:(PLVFPPTErrorCode)error;

@end

NS_ASSUME_NONNULL_END
