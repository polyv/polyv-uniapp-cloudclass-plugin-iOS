//
//  PLVLiveVideoAPI.h
//  PolyvCloudClassSDK
//
//  Created by zykhbl on 2018/7/27.
//  Copyright © 2018年 polyv. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PLVLiveDefine.h"
#import "PLVLiveVideoChannelMenuInfo.h"
#import "PLVPlaybackListModel.h"

extern NSString *const PLVApichatDomain;

NS_ASSUME_NONNULL_BEGIN

@interface PLVLiveVideoAPI : NSObject

/**
 设置私有的聊天室域名
 
 @param domainName 外部设置的私有域名，如果为空或没有设置，怎使用默认的域名
 */
+ (void)setPrivateApichatDomainName:(NSString *)domainName;

/**
 登录校验
 两种校验类型：1.直播相关参数校验 2.回放相关参数校验（vid为nil时进行直播相关参数校验，非空时进行回放相关参数校验）
 1.直播相关参数校验：channelId、appId、userId、appSecret
 2.回放相关参数校验：①vid、appId、channelId、userId；②vid、appId（channelId为0时，版本兼容）
 
 @param channelId 直播频道号
 @param vid 回放点播视频vid
 @param appId 云直播账号 应用Id
 @param userId 云直播账号 用户Id
 @param appSecret 云直播账号 应用密钥
 */
+ (void)verifyPermissionWithChannelId:(NSUInteger)channelId vid:(NSString *)vid appId:(NSString *)appId userId:(NSString *)userId appSecret:(NSString *)appSecret completion:(void (^)(NSDictionary *))completion failure:(void (^)(NSError *))failure;

/**
 校验后，根据channelId获取该频道的类型（普通直播，云课堂），和是否正在直播（废弃从0.13.1）
 
 @param channelId 频道号
 */
+ (void)liveStatus:(NSString *)channelId completion:(void (^)(BOOL, NSString *))completion failure:(void (^)(NSError *error))failure;

/// 获取频道的直播类型和直播状态（v2）
/// @param channelId 频道号
/// @param completion 请求完成块
/// @param failure 请求失败/错误块
+ (void)liveStatus2:(NSString *)channelId completion:(void (^)(NSString *liveType, PLVLiveStreamState liveState))completion failure:(void (^)(NSError *error))failure;

/**
 登录界面，校验后，根据vodId获取该频道的类型（普通直播，云课堂）
 
 @param vodId 回放视频ID
 */
+ (void)getVodType:(NSString *)vodId completion:(void (^)(BOOL))completion failure:(void (^)(NSError *error))failure;

/**
 加载自定义跑马灯

 @param url 自定义跑马灯地址
 @param channelId 直播频道号
 @param userId 云直播账号 用户ID
 @param code 自定义跑马灯附带参数
 @param completion 加载成功
 @param failure 加载失败
 */
+ (void)loadCustomMarquee:(NSURL *)url withChannelId:(NSUInteger)channelId userId:(NSString *)userId code:(NSString *)code completion:(void (^)(BOOL, NSDictionary *))completion failure:(void (^)(NSError *))failure;

/**
 获取频道菜单列表
 
 @param channelId 频道号
 */
+ (void)getChannelMenuInfos:(NSUInteger)channelId completion:(void(^)(PLVLiveVideoChannelMenuInfo *channelMenuInfo))completion failure:(void (^)(NSError *error))failure;

/**
 校验连麦权限(弃)
 使用 -getChatTokenWithChannelId:userId: 代替
 
 @param channelId 频道号
 @param appId 账号应用Id
 @param appSecret 账号应用密钥
 */
+ (void)requestAuthorizationForLinkingSocketWithChannelId:(NSUInteger)channelId Appld:(NSString *)appId appSecret:(NSString *)appSecret success:(void (^)(NSDictionary *))success failure:(void (^)(NSError *error))failure __deprecated;

/**
 获取 chatToken

 @param channelId 频道号
 @param userId 聊天室用户ID
 */
+ (void)getChatTokenWithChannelId:(NSInteger)channelId userId:(NSString *)userId completion:(void (^)(NSDictionary *data, NSError *error))completion;

/**
 加载聊天室开关信息
 
 @param roomId 频道号
 */
+ (void)loadChatroomFunctionSwitchWithRoomId:(NSUInteger)roomId completion:(void (^)(NSDictionary *switchInfo))completion failure:(void (^)(NSError *error))failure;

/**
 加载聊天室历史记录
 
 @param roomId 频道号
 @param startIndex 开始index
 @param endIndex 结束index
 */
+ (void)requestChatRoomHistoryWithRoomId:(NSUInteger)roomId startIndex:(NSUInteger)startIndex endIndex:(NSInteger)endIndex completion:(void (^)(NSArray *historyList))completion failure:(void (^)(NSError *error))failure;

/**
 放弃领奖
 
 @param channelId 频道号
 @param userId 聊天室用户ID
 */
+ (void)giveUpReceiveWithChannelId:(NSString *)channelId userId:(NSString *)userId completion:(void (^)(NSString *))completion failure:(void (^)(NSError *error))failure;

/**
 增加播放热度
 
 @param channelId 频道号
 @param times 新增 socket login 次数（收到自己的 login 消息一次 times +1）
 */
+ (void)increaseViewerWithChannelId:(NSString *)channelId times:(NSUInteger)times completion:(void (^)(NSInteger))completion failure:(void (^)(NSError *error))failure;

/**
 检测当前连麦状态
 
 @param roomId 频道号
 */
+ (void)requestLinkMicStatusWithRoomId:(NSUInteger)roomId completion:(void (^)(NSString *, NSString *))completion failure:(void (^)(NSError *))failure;

/**
 获取当前连麦列表
 
 @param roomId 频道号
 @param sessionId 当前直播的sessionId
 */
+ (void)requestLinkMicOnlineListWithRoomId:(NSUInteger)roomId sessionId:(NSString *)sessionId completion:(void (^)(NSDictionary *))completion failure:(void (^)(NSError *))failure;

/**
 发送图片
 
 @param image 图片
 @param imageName 图片名字
 */
+ (void)uploadImage:(UIImage *)image imageName:(NSString *)imageName progress:(void (^)(float))progressBlock success:(void (^_Nonnull)(NSDictionary * _Nonnull, NSString * _Nonnull, NSString * _Nonnull))successBlock fail:(void (^_Nonnull)(NSError * _Nonnull))failBlock;

/**
 点赞
 
 @param channelId 频道号
 @param viewerId 聊天室用户Id
 @param times 某段时间内（30秒内）的总点赞数
 */
+ (void)likeWithChannelId:(NSUInteger)channelId viewerId:(NSString *)viewerId times:(NSUInteger)times completion:(void (^)(void))completion failure:(void (^)(NSError *error))failure;

/**
 发送中奖信息（自 v0.11.1 失效）
 
 @param data 中奖信息
 */
+ (void)postLotteryWithData:(NSDictionary *)data completion:(void (^)(void))completion failure:(void (^)(NSError *error))failure;

/**
 发送中奖信息（自 v0.11.1 生效）
 
 @param data 中奖信息
 */
+ (void)newPostLotteryWithData:(NSDictionary *)data completion:(void (^)(void))completion failure:(void (^)(NSError *error))failure;

/**
 普通直播，获取推流端是旧的推流端（主讲人走CDN视频，连麦走RTC音频），还是新的推流端（主讲人走RTC视频，连麦走RTC）
 
 @param channelId 频道号
 */
+ (void)rtcEnabled:(NSUInteger)channelId completion:(void (^)(BOOL))completion failure:(void (^)(NSError *))failure;

/**
  获取账号积分打赏设置
  
  @param channelId 频道号
  */
 + (void)requestPointSettingWithChannelId:(NSUInteger)channelId completion:(nullable void (^)(NSDictionary *))completion failure:(nullable void (^)(NSError *))failure;

 /**
 获取观众的积分信息
  
 @param viewerId 聊天室用户Id
 @param nickName 观众的用户昵称
 @param channelId 频道号
 */
 + (void)requestViewerPointWithViewerId:(NSString *)viewerId nickName:(NSString *)nickName channelId:(NSUInteger)channelId completion:(nullable void (^)(NSString *))completion failure:(nullable void (^)(NSError *))failure;

 /**
 观众打赏积分道具
  
 @param viewerId 聊天室用户Id
 @param nickName 观众的昵称
 @param avatar 观众的头像地址
 @param goodId 商品id
 @param goodNum 商品数量
 @param channelId 频道号
 */
 + (void)requestViewerRewardPointWithViewerId:(NSString *)viewerId nickName:(NSString *)nickName avatar:(NSString *)avatar goodId:(NSInteger)goodId goodNum:(NSInteger)goodNum channelId:(NSUInteger)channelId completion:(nullable void (^)(NSString *))completion failure:(nullable void (^)(NSError *))failure;

/**
 连麦id和聊天室用户id关联
 
 @param channelId 频道号
 @param viewerId 聊天室的用户Id
 @param linkMicId 连麦id
 */
+ (void)requestViewerIdLinkMicIdRelate:(NSString *)channelId viewerId:(NSString *)viewerId linkMicId:(NSString *)linkMicId completion:(nullable void (^)(void))completion failure:(nullable void (^)(NSError *))failure;

#pragma mark - 直播回放
/**
 获取视频弹幕信息
 */
+ (void)loadDanmuWithVid:(NSString *)vid time:(NSString *)time msgId:(NSUInteger)msgId limit:(NSUInteger)limit completion:(void (^)(NSArray *danmuArr, NSError *error))completion;

/**
 新增回放弹幕
 */
+ (void)addDanmuWithVid:(NSString *)vid msg:(NSString *)msg time:(NSString *)time sessionId:(NSString *)sessionId msgType:(NSString *)msgType user:(NSString *)user completion:(void (^)(NSDictionary *respondDict, NSError *error))completion;

/// 查询回放视频的视频列表信息
/// @param channelId 频道号
/// @param listType playback-回放列表，vod-点播列表; 默认普通直播场景为vod，三分屏为playback
/// @param page 页数，默认每页显示12条数据
/// @param pageSize 每页显示的数据条数，0为默认值
/// @param appId 用户appId
/// @param appSecret 用户appSecret
/// @param completion 请求完成块
+ (void)requestPlaybackList:(NSString *)channelId listType:(NSString *)listType page:(NSUInteger)page pageSize:(NSUInteger)pageSize appId:(NSString *)appId appSecret:(NSString *)appSecret completion:(void (^)(PLVPlaybackListModel *model, NSError *error))completion;

@end

NS_ASSUME_NONNULL_END
