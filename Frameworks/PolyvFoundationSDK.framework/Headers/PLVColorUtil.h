//
//  PLVColorUtil.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/9/27.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define UIColorFromRGB(rgbStr) [PLVColorUtil colorFromHexString:rgbStr]
#define UIColorFromRGBA(rgbStr,a) [PLVColorUtil colorFromHexString:rgbStr alpha:a]

@interface PLVColorUtil : NSObject

+ (UIColor *)colorFromHexString:(NSString *)hexString;

+ (UIColor *)colorFromHexString:(NSString *)hexString alpha:(float)alpha;

+ (UIImage *)createImageWithColor:(UIColor *)color;

@end

NS_ASSUME_NONNULL_END
