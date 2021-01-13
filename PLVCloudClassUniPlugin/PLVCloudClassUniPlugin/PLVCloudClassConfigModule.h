//
//  PLVCloudClassConfigModule.h
//  PLV-CloudClassUniPlugin
//
//  Created by ysh on 2020/11/6.
//

#import <Foundation/Foundation.h>
#import "WeexSDK.h"

NS_ASSUME_NONNULL_BEGIN

@interface PLVCloudClassConfigModule : NSObject <WXModuleProtocol>

+(NSString *)viewerId;
+(NSString *)viewerName;
+(NSString *)viewerAvatar;

@end

NS_ASSUME_NONNULL_END
