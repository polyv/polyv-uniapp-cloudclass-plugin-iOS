//
//  PLVCloudClassUtils.m
//  PLVCloudClassUniPlugin
//
//  Created by ysh on 2020/12/1.
//

#import <Foundation/Foundation.h>
#import "PLVCloudClassUtils.h"

@implementation PLVCloudClassUtils

+(BOOL)isValidString:(NSString *)param {
    return (param && [param isKindOfClass:[NSString class]] && param.length > 0);
}

+(BOOL)validateVid:(NSString *)vid {
    if(![self isValidString:vid]){
        return NO;
    } else {
        NSString *VID = @"^[[a-z]|[0-9]]{32}_[[a-z]|[0-9]]$";
        NSPredicate *regexVid = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",VID];
        return [regexVid evaluateWithObject:vid];
    }
}

+(NSString *)stringValueWithDictionary:(NSDictionary *)dict
                                forKey:(NSString *)key
                          defaultValue:(NSString *)defaultValue {
    if (![defaultValue isKindOfClass:[NSString class]] || defaultValue.length == 0) {
        defaultValue = nil;
    }
    
    if (!dict || ![dict isKindOfClass:[NSDictionary class]]) {
        return defaultValue;
    }
    
    if (!key || ![key isKindOfClass:[NSString class]] || key.length == 0) {
        return defaultValue;
    }
    
    return dict[key] ?: defaultValue;
}

@end
