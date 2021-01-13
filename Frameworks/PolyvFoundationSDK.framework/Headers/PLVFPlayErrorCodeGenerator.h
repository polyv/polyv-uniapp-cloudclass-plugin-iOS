//
//  PLVFPlayErrorCodeGenerator.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/12/11.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVFErrorBaseCodeDefine.h"

typedef NS_ENUM(NSInteger, PLVFPlayErrorCode){
    PLVFPlayErrorCodeForExample = 000
};

NS_ASSUME_NONNULL_BEGIN

@interface PLVFPlayErrorCodeGenerator : NSObject

+ (NSInteger)errorCode:(PLVFPlayErrorCode)error;

+ (NSString *)errorDescription:(PLVFPlayErrorCode)error;

@end

NS_ASSUME_NONNULL_END
