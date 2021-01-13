//
//  PLVSocketIOProtocol.h
//  PolyvBusinessSDK
//
//  Created by ftao on 2020/8/6.
//  Copyright © 2020 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVSocketListenerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol PLVSocketIOProtocol <NSObject>

@property (nonatomic, assign, readonly) PLVSocketStatus status;

@property (nonatomic, strong, readonly) NSString *socketId;

#pragma mark Connect

/**
 连接服务器
 */
- (void)connect;

/**
 重连服务器
 */
- (void)reconnect;

/**
 断开服务器连接
 */
- (void)disconnect;

/**
 清理释放资源
 */
- (void)clear;

#pragma mark Listen

- (void)addListener:(id<PLVSocketListenerProtocol>)listener;

- (void)removeListener:(id<PLVSocketListenerProtocol>)listener;

- (void)removeAllListeners;

#pragma mark Message Emit

/**
 提交 socket "message" 事件消息

 @param content 消息内容，NSString 或 NSDictionary 类型
 */
- (void)emitMessage:(id)content;

/**
 提交 socket "message" 事件消息
 
 @param content 消息内容，NSString 或 NSDictionary 类型
 @param timeout ACK 回调超时，默认 0
 @param callback ACK 回调
 */
- (void)emitMessage:(id)content timeout:(double)timeout callback:(void (^)(NSArray *ackArray))callback;

/**
 提交 socket 特定事件消息
 
 @param event 事件名
 @param content 消息内容，NSString 或 NSDictionary 类型
 */
- (void)emitMessage:(NSString *)event content:(id)content;

/**
 提交 socket 特定事件消息

 @param event 消息事件，默认 "message"
 @param content 消息内容，NSString 或 NSDictionary 类型
 @param timeout ACK 回调超时，默认 0
 @param callback ACK 回调
 */
- (void)emitMessage:(NSString *)event content:(id)content timeout:(double)timeout callback:(void (^)(NSArray *ackArray))callback;

@end

NS_ASSUME_NONNULL_END
