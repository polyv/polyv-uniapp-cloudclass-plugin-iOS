//
//  PolyvUniCloudClassConfig.m
//  PLVCloudClassUniPlugin
//
//  Created by Sakya on 2021/5/12.
//

#import "PolyvUniCloudClassConfig.h"

@implementation PolyvUniCloudClassConfig

+ (instancetype)sharedInstance {
    static PolyvUniCloudClassConfig *cloudClassConfig = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        cloudClassConfig = [[super allocWithZone:NULL] init];
    });
    return cloudClassConfig;
}

@end
