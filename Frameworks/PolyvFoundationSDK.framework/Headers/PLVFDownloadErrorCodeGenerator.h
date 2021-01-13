//
//  PLVFDownloadErrorCodeGenerator.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/12/11.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFDownloadErrorCode){
    PLVFDownloadErrorCodeForExample = 000
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFDownloadErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFDownloadErrorCode)error;

+ (NSString *)errorDescription:(PLVFDownloadErrorCode)error;

@end

NS_ASSUME_NONNULL_END
