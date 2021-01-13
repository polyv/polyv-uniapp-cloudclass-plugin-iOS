//
//  PLVSocketListenerProtocol.h
//  PolyvBusinessSDK
//
//  Created by ftao on 2020/7/28.
//  Copyright © 2020 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVBSocketDefine.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PLVSocketIOProtocol;

@protocol PLVSocketListenerProtocol <NSObject>

@optional

/// 监听者监听的事件，默认或为nil时回调除 “message” 外的其他事件
@property (nonatomic, strong) NSArray<kPLVBSocketEvent> *listenEvents;

/**
 socket 状态改变
 */
- (void)socket:(id<PLVSocketIOProtocol>)socket didStatusChange:(PLVSocketStatus)status string:(NSString *)string;

/**
 socket "message" 事件
 */
- (void)socket:(id<PLVSocketIOProtocol>)socket didReceiveMessage:(NSString *)string jsonDict:(NSDictionary *)jsonDict;

/**
 socket 除了 “message” 事件之外其他事件消息
 */
- (void)socket:(id<PLVSocketIOProtocol>)socket didReceiveEvent:(NSString *)event jsonDict:(NSDictionary *)jsonDict;

/**
 socket 本地错误信息
 */
- (void)socket:(id<PLVSocketIOProtocol>)socket localError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
