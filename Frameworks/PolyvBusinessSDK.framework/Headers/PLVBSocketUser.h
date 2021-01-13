//
//  PLVBSocketUser.h
//  PolyvBusinessSDK
//
//  Created by ftao on 2020/3/20.
//  Copyright © 2020 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVBSocketDefine.h"

/// Socket 登陆对象
@interface PLVBSocketUser : NSObject

@property (nonatomic, copy, readonly) NSString *roomId;           // 房间号(值默认为channelId)
@property (nonatomic, copy, readonly) NSString *channelId;        // 频道号
@property (nonatomic, copy, readonly) NSString *userId;           // 登录用户Id
@property (nonatomic, copy, readonly) NSString *nickName;         // 登录用户名
@property (nonatomic, copy, readonly) NSString *avatarUrl;        // 登录用户头像地址
@property (nonatomic, copy, readonly) NSString *actor;            // 登陆用户头衔（自定义）
@property (nonatomic, readonly) PLVBSocketUserType userType;      // 登陆用户类型
@property (nonatomic, copy, readonly) NSString *userIdForAccount; // 用户帐号Id

/// 连麦Id(不支持自定义)
@property (nonatomic, copy, readonly) NSString *linkMicId;

/// 生成一个登陆对象1
/// @param channelId 频道号，不可为空
/// @param userId 登录用户Id，为nil时默认生成
/// @param nickName 登录用户名，为nil时默认生成
/// @param avatarUrl 登录用户头像地址，为nil时默认生成
/// @param userType 登陆用户类型
/// @param userIdForAccount 用户帐号Id，可为nil
+ (instancetype)socketLoginUser:(NSString *)channelId
                         userId:(NSString *)userId
                       nickName:(NSString *)nickName
                      avatarUrl:(NSString *)avatarUrl
                       userType:(PLVBSocketUserType)userType
               userIdForAccount:(NSString *)userIdForAccount;

/// 生成一个登陆对象2
/// @param channelId 频道号
/// @param userId 登录用户Id，为nil时默认生成
/// @param nickName 登录用户名，为nil时默认生成
/// @param avatarUrl 登录用户头像地址，为nil时默认生成
/// @param actor 登陆用户头衔（自定义），可为nil
/// @param getCup 奖杯功能（参与者）
/// @param userType 登陆用户类型
/// @param userIdForAccount 用户帐号Id，可为nil
+ (instancetype)socketLoginUser:(NSString *)channelId
                         userId:(NSString *)userId
                       nickName:(NSString *)nickName
                      avatarUrl:(NSString *)avatarUrl
                          actor:(NSString *)actor
                         getCup:(BOOL)getCup
                       userType:(PLVBSocketUserType)userType
               userIdForAccount:(NSString *)userIdForAccount;

/// 生成一个讲师登陆对象
/// @param channelId 频道号
/// @param nickName 登录用户名，为nil时默认生成
/// @param avatarUrl 登录用户头像地址，为nil时默认生成
+ (instancetype)socketLoginTeacherUser:(NSString *)channelId
                              nickName:(NSString *)nickName
                             avatarUrl:(NSString *)avatarUrl;

- (void)updateRoomId:(NSString *)roomId;

#pragma mark - 内部 API

/// 生成一个登陆用户元数据
- (NSDictionary *)createLoginInfo;

@end
