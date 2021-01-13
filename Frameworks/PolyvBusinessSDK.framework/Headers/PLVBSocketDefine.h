//
//  PLVBSocketDefine.h
//  PolyvBusinessSDK
//
//  Created by ftao on 2020/3/20.
//  Copyright © 2020 polyv. All rights reserved.
//

#ifndef PLVBSocketDefine_h
#define PLVBSocketDefine_h

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

typedef NS_ENUM(NSInteger, PLVSocketErrorCode) {
    PLVSocketErrorCodeNotConnected = -11000,
    PLVSocketErrorCodeParamIllegal = -11001,
    PLVSocketErrorCodeParseFailed  = -11002,
    PLVSocketErrorCodeDataInvalid  = -11003,
};

/// Define "userType" constant type
typedef NS_ENUM(NSUInteger, PLVBSocketUserType) {
    PLVBSocketUserTypeUnknown   = 0,
    
    PLVBSocketUserTypeStudent   = 1, // 普通观众
    PLVBSocketUserTypeSlice     = 2, // 云课堂学员
    PLVBSocketUserTypeViewer    = 3, // 客户端的参与者
    
    PLVBSocketUserTypeGuest     = 4, // 嘉宾
    PLVBSocketUserTypeTeacher   = 5, // 讲师
    PLVBSocketUserTypeAssistant = 6, // 助教
    PLVBSocketUserTypeManager   = 7, // 管理员
    
    PLVBSocketUserTypeDummy     = 8
};

BOOL IsSpecialIdentityOfUserType(PLVBSocketUserType userType);

PLVBSocketUserType PLVBSocketUserTypeWithString(NSString *userType);

NSString *PLVSStringWithSocketUserType(PLVBSocketUserType userType, BOOL english);

/// Define "userType" constant string
extern NSString *const kPLVBSocketUserTypeStudent;
extern NSString *const kPLVBSocketUserTypeSlice;
extern NSString *const kPLVBSocketUserTypeViewer;

extern NSString *const kPLVBSocketUserTypeGuest;
extern NSString *const kPLVBSocketUserTypeTeacher;
extern NSString *const kPLVBSocketUserTypeAssistant;
extern NSString *const kPLVBSocketUserTypeManager;

extern NSString *const kPLVBSocketUserTypeDummy;

/// Define socket events

typedef NSString * kPLVBSocketEvent;

/// 通用事件
extern NSString *const kPLVBSocketEvent_message;

/// 自定义消息事件
extern NSString *const kPLVBSocketEvent_customMessage;

/// 连麦相关事件
extern NSString *const kPLVBSocketEvent_joinRequest;
extern NSString *const kPLVBSocketEvent_joinResponse;
extern NSString *const kPLVBSocketEvent_joinSuccess;
extern NSString *const kPLVBSocketEvent_joinLeave;
extern NSString *const kPLVBSocketEvent_MuteUserMedia;
extern NSString *const kPLVBSocketEvent_switchView;

/// 助教翻页事件
extern NSString *const kPLVBSocketEvent_assistantSliceControl;

#endif /* PLVBSocketDefine_h */
