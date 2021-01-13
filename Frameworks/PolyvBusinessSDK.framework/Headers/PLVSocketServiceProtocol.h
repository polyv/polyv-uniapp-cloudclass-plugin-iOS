//
//  PLVSocketServiceProtocol.h
//  PolyvBusinessSDK
//
//  Created by ftao on 2020/7/28.
//  Copyright © 2020 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PolyvFoundationSDK/PLVFSocketErrorCodeGenerator.h>
#import "PLVBSocketUser.h"

@protocol PLVSocketServiceProtocol <NSObject>

@property (nonatomic, strong) PLVBSocketUser *loginUser;

/// 后台是否开启了分房间功能，登陆成功后值有效
@property (nonatomic, assign, readonly) BOOL childRoomEnabled;

/// 房间id，默认为为频道id值，分房间开启后该值会有变化
@property (nonatomic, copy, readonly) NSString *roomId;

- (void)loginSocketServerWithUser:(PLVBSocketUser *)loginUser;

- (void)loginSocketServer;

- (PLVFSocketErrorCode)socketLoginAckParser:(NSString *)ackString;

@end
