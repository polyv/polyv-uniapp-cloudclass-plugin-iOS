//
//  PLVFErrorBaseCodeDefine.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/12/12.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 错误码模块码枚举值
typedef NS_ENUM(NSInteger, PLVFErrorCodeModul) {
    PLVFErrorCodeModulPlay = 0,
    PLVFErrorCodeModulDownload = 1,
    PLVFErrorCodeModulUpload = 2,
    PLVFErrorCodeModulRecord = 3,
    PLVFErrorCodeModulRtmp = 4,
    PLVFErrorCodeModulChat = 5,
    PLVFErrorCodeModulLink = 6,
    PLVFErrorCodeModulPPT = 7,
    PLVFErrorCodeModulInit = 8,
    PLVFErrorCodeModulSocket = 9, //原 PLVFErrorCodeModulNetwork
    PLVFErrorCodeModulHttp = 10,
    PLVFErrorCodeModulInteraction = 11
};

/*
 错误码由7位组成
 平台码（1位）+ 模块码（2位）+ 具体错误码（4位）
 具体错误码为：一级错误码（2位）+ 二级错误码（2位）
 以下接口说明把这个7位错误码用：ABBCCDD 表示
 */

/// 根据模块枚举值获取 “ABB0000”
NSInteger PLVFErrorBaseCode(NSInteger modul);

/// 根据错误码获取模块码 “BB”
NSInteger PLVFErrorModulCode(NSInteger errorCode);

/// 根据错误码获取“一级错误码” “CC”
NSInteger PLVFErrorModulTopLevelCode(NSInteger errorCode);

/// 根据错误码获取“具体错误码” “CCDD”
NSInteger PLVFErrorDetailCode(NSInteger errorCode);

@interface PLVFErrorBaseCodeDefine : NSObject

@end

NS_ASSUME_NONNULL_END
