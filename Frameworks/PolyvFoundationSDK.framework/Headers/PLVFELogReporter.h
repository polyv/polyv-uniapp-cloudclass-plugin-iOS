//
//  PLVFELogReporter.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/12/5.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <PolyvFoundationSDK/PolyvFoundationSDK.h>
#import "PLVFLogReporter.h"

@class PLVFELogModel;

NS_ASSUME_NONNULL_BEGIN

@interface PLVFELogReporter : PLVFLogReporter

- (void)registerWithUserId:(NSString *)userId secretkey:(NSString *)secretkey;

- (void)registerWithChannelId:(NSString *)channelId appId:(NSString *)appId appSecret:(NSString *)appSecret userId:(NSString *)userId;

- (void)registerWithChannelId:(NSString *)channelId appId:(NSString *)appId appSecret:(NSString *)appSecret userId:(NSString *)userId vId:(NSString *)vid;

- (void)unregister;

- (PLVFELogModel *)generateTemplateModel;

@end

NS_ASSUME_NONNULL_END
