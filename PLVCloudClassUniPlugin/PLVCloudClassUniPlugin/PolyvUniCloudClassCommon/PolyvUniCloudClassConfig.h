//
//  PolyvUniCloudClassConfig.h
//  PLVCloudClassUniPlugin
//
//  Created by Sakya on 2021/5/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PolyvUniCloudClassConfig : NSObject
/// 当设置为自定义跑马灯时跑马灯参数
@property (nonatomic, copy) NSString *code;

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
