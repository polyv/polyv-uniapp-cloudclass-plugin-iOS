//
//  PLVLogger.h
//  PolyvFoundationSDK
//
//  Created by zykhbl on 2018/8/6.
//  Copyright © 2018年 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PLVLogger : NSObject

+ (void)logWithFormat:(NSString *)format, ... NS_FORMAT_FUNCTION(1,2);

@end
