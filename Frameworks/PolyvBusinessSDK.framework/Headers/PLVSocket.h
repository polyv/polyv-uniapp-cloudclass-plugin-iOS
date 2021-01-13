//
//  PLVSocket.h
//  PolyvBusinessSDK
//
//  Created by ftao on 2019/10/16.
//  Copyright © 2019 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PLVSocketErrorCode) {
    PLVSocketErrorCodeNotConnected = -11000,
    PLVSocketErrorCodeParamIllegal = -11001,
    PLVSocketErrorCodeParseFailed  = -11002,
    PLVSocketErrorCodeDataInvalid  = -11003,
};

typedef NS_ENUM(NSUInteger, PLVSocketStatus) {
    PLVSocketStatusNotConnected = 0,
    
    PLVSocketStatusDisconnected = 1,
    PLVSocketStatusConnecting   = 2,
    PLVSocketStatusConnected    = 3,
    PLVSocketStatusConnectError = 4,
    
    PLVSocketStatusLogining     = 5,
    PLVSocketStatusLoginSuccess = 6, /* param string: ack callback*/
    PLVSocketStatusLoginFailed  = 7  /* param string: ack callback*/
};

NSString *PLVNameStringWithSocketStatus(PLVSocketStatus status);

@class PLVSocket;
@protocol PLVSocketListenerProtocol <NSObject>

@optional

/// 监听者监听的事件，默认或为nil时回调除 “message” 外的其他事件
@property (nonatomic, strong) NSArray<NSString *> *listenEvents;

/**
 回调 Socket 状态
 */
- (void)socket:(PLVSocket *)socket didStatusChange:(PLVSocketStatus)status string:(NSString *)string;

/**
 只回调 "message" 事件
 */
- (void)socket:(PLVSocket *)socket didReceiveMessage:(NSString *)string jsonDict:(NSDictionary *)jsonDict;

/**
 回调主动监听的 "listenEvents" 事件，不含 “message” 事件
 */
- (void)socket:(PLVSocket *)socket didReceiveEvent:(NSString *)event jsonDict:(NSDictionary *)jsonDict;

/**
 回调本地错误信息
 */
- (void)socket:(PLVSocket *)socket localError:(NSError *)error;

@end

@interface PLVSocket : NSObject

@property (nonatomic, assign, readonly) PLVSocketStatus status;

@property (nonatomic, strong, readonly) NSString *socketId;

@property (nonatomic, strong, readonly) NSPointerArray *listeners;

@property (nonatomic, assign) BOOL debugMode;

/**
 初始化 socket 连接配置
 */
- (void)setupConnectToken:(NSString *)connectToken url:(NSString *)url log:(BOOL)log;

/**
 便利初始化 socket 连接
 */
- (instancetype)initWithConnectToken:(NSString *)connectToken log:(BOOL)log;

/**
 便利初始化自定义 socket 服务器连接
 */
- (instancetype)initWithConnectToken:(NSString *)connectToken url:(NSString *)url log:(BOOL)log;

/**
 添加自定义监听的事件
 */
- (void)addListenEvents:(NSArray<NSString *> *)events;

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

#pragma mark Setter

/**
  更新 status PLVSocketStatusLogin 状态

 @param status PLVSocketStatusLogining
               PLVSocketStatusLoginSuccess
               PLVSocketStatusLoginFailed
 */
- (void)setSocketLoginStatus:(PLVSocketStatus)status string:(NSString *)string;

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

#pragma mark Error

- (void)exportErrorInfo:(NSString *)errorInfo errorCode:(PLVSocketErrorCode)errorCode;

@end
