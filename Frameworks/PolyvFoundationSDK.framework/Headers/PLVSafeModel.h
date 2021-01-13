//
//  PLVSafeModel.h
//  XYJJsonSafeConvert
//
//  Created by MissYasiky on 2019/7/17.
//  Copyright © 2019 plv. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PLVJsonValidatorProtocol <NSObject>

/**
 json 字段不同时的自动转换器
 @return 与属性名不符的 json 字段
 */
+ (NSDictionary *)jsonConvertor;
    
/**
 json 格式校验器
 @return 如果需要校验返回的 json 格式，需在子类覆写这个方法
 */
+ (NSDictionary *)jsonValidator;
    
/**
 校验 json 数据是否按照 "+jsonValidator" 的格式返回
 PLVSafeModel 已执行了该方法，子类无需执行
 @param json 被校验的 json 数据
 @param jsonValidator 用于校验数据的合法格式
 @return YES：格式合法，NO：格式非法
 */
- (BOOL)validateJSON:(id)json withValidator:(id)jsonValidator;
    
@end

@interface PLVSafeModel : NSObject<PLVJsonValidatorProtocol>

/**
 将 json 数据转换为数据模型
 如果数据模型类覆写了方法 "+jsonValidator"，则会进行数据格式校验，格式不符返回 nil
 @param dictionary 待转换的 json 数据
 @return 转换后的数据模型
 */
- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

@end

NS_ASSUME_NONNULL_END
