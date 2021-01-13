//
//  PLVFUploadErrorCodeGenerator.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/12/11.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFUploadErrorCode){
    PLVFUploadErrorCodeForExample = 000
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFUploadErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFUploadErrorCode)error;

+ (NSString *)errorDescription:(PLVFUploadErrorCode)error;

@end

NS_ASSUME_NONNULL_END
