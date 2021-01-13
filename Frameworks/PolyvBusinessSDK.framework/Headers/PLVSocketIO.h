//
//  PLVSocketIO.h
//  PolyvBusinessSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVSocketObject.h"

extern NSString *const PLVSocketServerUrl;

/// socketIO 连接状态
typedef NS_ENUM(NSInteger, PLVSocketIOState) {
    /// SocketIO 未连接
    PLVSocketIOStatusNotConnected = 0,
    /// SocketIO 失去连接
    PLVSocketIOStateDisconnected = 1,
    /// SocketIO 连接中
    PLVSocketIOStateConnecting = 2,
    /// SocketIO 连接成功
    PLVSocketIOStateConnected = 3,
    /// SocketIO 连接出错
    PLVSocketIOStateConnectError = 4,
};

/// 用户状态
typedef NS_ENUM(NSInteger, PLVSocketUserState) {
    /// 用户未登录
    PLVSocketUserStateNotLogin = 0,
    /// 用户退出登录
    PLVSocketUserStateLogout = 1,
    /// 用户登录中
    PLVSocketUserStateLogining = 2,
    /// 用户登录成功
    PLVSocketUserStateLogined = 3,
    /// 用户登录失败
    PLVSocketUserStateLoginError = 4,
};

NSString *PLVNameStringWithSocketUserState(PLVSocketUserState userState);

@class PLVSocketIO;

/**
 PLVSocketIO 代理回调消息
 */
@protocol PLVSocketIODelegate <NSObject>

#pragma mark Connect state
@required
/** SocketIO 连接服务器成功*/
- (void)socketIO:(PLVSocketIO *)socketIO didConnectWithInfo:(NSString *)info;

@optional
/** SocketIO 和服务器失去连接*/
- (void)socketIO:(PLVSocketIO *)socketIO didDisconnectWithInfo:(NSString *)info;

/** SocketIO 连接服务器出错*/
- (void)socketIO:(PLVSocketIO *)socketIO connectOnErrorWithInfo:(NSString *)info;

/** SocketIO 重新连接服务器*/
- (void)socketIO:(PLVSocketIO *)socketIO reconnectWithInfo:(NSString *)info;

#pragma mark Login state
/** SocketIO 用户登录失败*/
- (void)socketIO:(PLVSocketIO *)socketIO didLoginFailed:(NSDictionary *)jsonDict;

#pragma mark Socket message
/** SocketIO 收到聊天室（公聊）消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceivePublicChatMessage:(PLVSocketChatRoomObject *)chatObject;

/** SocketIO 收到聊天室（私聊）消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceivePrivateChatMessage:(PLVSocketChatRoomObject *)chatObject;

/** SocketIO 收到连麦消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveLinkMicMessage:(PLVSocketLinkMicObject *)linkMicObject;

/** SocketIO 收到互动课堂消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveClassMessage:(PLVSocketClassObject *)classObject;

/** SocketIO 收到云课堂消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceivePPTMessage:(NSString *)json;

/** SocketIO 收到赠送奖杯的消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveSendCupMessage:(NSDictionary *)jsonDict;

/** SocketIO 收到图文直播消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveTuwenMessage:(NSString *)json eventType:(NSString *)event;

#pragma mark Interactive message
/** SocketIO 收到公告信息或删除公告*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveBulletinMessage:(NSString *)json result:(int)result;

/** SocketIO 收到答题卡问题或答案信息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveQuestionMessage:(NSString *)json result:(int)result;

/** SocketIO 收到问卷信息并打开或关闭问卷*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveQuestionnaireMessage:(NSString *)json result:(int)result;

/** SocketIO 收到抽奖信息并打开或结束抽奖*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveLotteryMessage:(NSString *)json result:(int)result;

/** SocketIO 收到签到信息并打开或结束签到*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveSignInMessage:(NSString *)json result:(int)result;

#pragma mark Custom message
/** SocketIO 收到自定义消息*/
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveCustomMessage:(NSDictionary *)customMessage;

#pragma mark Error
/** 本地出错信息回调*/
- (void)socketIO:(PLVSocketIO *)socketIO localError:(NSString *)description;

#pragma mark Deprecated(废弃)

/** SocketIO 用户状态改变
 使用-loginSocketServer:timeout:callback:替代，登录状态由ack回调获取
 */
- (void)socketIO:(PLVSocketIO *)socketIO didUserStateChange:(PLVSocketUserState)userState __deprecated;

@end

/**
 SocketIO 对象
 */
@interface PLVSocketIO : NSObject

/// SocketIO 代理对象
@property (nonatomic, weak) id <PLVSocketIODelegate> delegate;
/// Socket id
@property (nonatomic, strong, readonly) NSString *socketId;
/// 房间号/频道号
@property (nonatomic, assign, readonly) NSUInteger roomId;
/// 用户Id（由PLVSocketObjec登录对象生成）
@property (nonatomic, strong, readonly) NSString *userId;
/// socketIO 连接状态
@property (nonatomic, assign, readonly) PLVSocketIOState socketIOState;
/// Socket 用户信息（当前不建议使用该参数，请使用本地创建到的登录对象）
@property (nonatomic, strong, readonly) PLVSocketObject *user __deprecated;
/// socketIO 用户登录状态（非PLVSocketUserStateLogined时不一定未登录成功，所以该状态只可参考使用）
@property (nonatomic, assign, readonly) PLVSocketUserState userState __deprecated;

/// debug模式
@property (nonatomic, assign) BOOL debugMode;

#pragma mark - Base Methods

/**
 初始化 SocketIO，使用 -connect 连接

 @param connectToken 连接 token，Socket、连麦授权接口中获取
 @param enableLog 是否输出调试信息
 @return 实例对象
 */
- (instancetype)initSocketIOWithConnectToken:(NSString *)connectToken enableLog:(BOOL)enableLog;

/**
 初始化 SocketIO，使用 -connect 连接

 @param connectToken 连接 token，Socket、连麦授权接口中获取
 @param url 服务器地址，为空时使用默认地址
 @param enableLog 是否输出调试信息
 @return SocketIO 实例对象
 */
- (instancetype)initSocketIOWithConnectToken:(NSString *)connectToken url:(NSString *)url enableLog:(BOOL)enableLog;

/**
 连接 SocketIO 服务器
 */
- (void)connect;

/**
 重新连接 SocketIO 服务器
 */
- (void)reconnect;

/**
 关闭 SocketIO 连接
 */
- (void)disconnect;

/**
 移除监听所有 SocketIO 事件
 */
- (void)removeAllHandlers;

#pragma mark - Emit Message

/**
 登录 Socket 服务器（新 > 0.9.0）

 @param loginObject 登录对象
 @param timeout 应答超时时间
 @param callback 服务器应答回调
 */
- (void)loginSocketServer:(PLVSocketObject *)loginObject timeout:(double)timeout callback:(void (^)(NSArray *ackArray))callback;

/**
 发送消息

 @param socketObject Socket 对象
 */
- (void)emitMessageWithSocketObject:(PLVSocketObject *)socketObject;

/**
 发送带 ACK 回调的消息（Beta）

 @param socketObject Socket 对象
 @param after 回调超时
 @param callback Ack 回调
 */
- (void)emitACKWithSocketObject:(PLVSocketObject *)socketObject after:(double)after callback:(void (^)(NSArray *ackArray))callback;

/**
 发送自定义消息
 
 @param event 自定义消息事件名
 @param roomId 房间号
 @param emitMode 类型：0 表示广播所有人包括自己，1 表示广播给除了自己的其他人，2 表示只发送给自己
 @param data 自定义消息内容
 @param tip 自定义提示消息，为空时默认为 "发送了自定义消息"
 */
- (void)emitCustomEvent:(NSString *)event roomId:(NSUInteger)roomId emitMode:(int)emitMode data:(NSDictionary *)data tip:(NSString *)tip;

/**
 发送带 ACK 回调的消息（Beta）

 @param event 自定义消息事件名
 @param roomId 房间号
 @param emitMode 类型：0 表示广播所有人包括自己，1 表示广播给除了自己的其他人，2 表示只发送给自己
 @param data 自定义消息内容
 @param tip 自定义提示消息，为空时默认为 "发送了自定义消息"
 @param after 回调超时
 @param callback Ack 回调
 */
- (void)emitCustomEvent:(NSString *)event roomId:(NSUInteger)roomId emitMode:(int)emitMode data:(NSDictionary *)data tip:(NSString *)tip after:(double)after callback:(void (^)(NSArray *ackArray))callback;

/// 发送消息
- (void)emitEvent:(NSString *)event withJsonString:(NSString *)jsonString;

/// 连麦成功后，socket重连，要发送reJoinMic事件
- (void)reJoinMic:(NSString *)token;

@end
