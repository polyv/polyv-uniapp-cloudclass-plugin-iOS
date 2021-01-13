//
//  PLVLiveVideoChannelMenuInfo.h
//  PolyvCloudClassSDK
//
//  Created by zykhbl(zhangyukun@polyv.net) on 2018/7/19.
//  Copyright © 2018年 polyv.net. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PolyvFoundationSDK/PLVSafeModel.h>

/// tab子菜单信息
@interface PLVLiveVideoChannelMenu : PLVSafeModel

/// 菜单Id
@property (nonatomic, copy, readonly) NSString *menuId;
/// 菜单类型
@property (nonatomic, copy, readonly) NSString *menuType;
/// 菜单名称
@property (nonatomic, copy, readonly) NSString *name;
/// 菜单内容，html文本，有可能为NSNull
@property (nonatomic, copy, readonly) NSString *content;
/// 菜单显示顺序
@property (nonatomic, copy, readonly) NSNumber *ordered;

@end


/// 频道菜单信息
@interface PLVLiveVideoChannelMenuInfo : PLVSafeModel

/// 直播标题
@property (nonatomic, copy, readonly) NSString *name;
/// 主持人头像
@property (nonatomic, copy, readonly) NSString *coverImage;
/// 主持人
@property (nonatomic, copy, readonly) NSString *publisher;
/// 点赞数
@property (nonatomic, copy, readonly) NSNumber *likes;
/// 观看数
@property (nonatomic, copy, readonly) NSNumber *pageView;
/// 直播时间
@property (nonatomic, copy, readonly) NSString *startTime;
/// 直播状态
@property (nonatomic, copy, readonly) NSString *status;
/// 观看状态
@property (nonatomic, copy, readonly) NSString *watchStatus;
/// 频道菜单列表
@property (nonatomic, strong, readonly) NSArray<PLVLiveVideoChannelMenu*> *channelMenus;

/// 直播场景
@property (nonatomic, strong, readonly) NSString *scene;
/// 是否有回放视频
@property (nonatomic, assign, readonly) BOOL hasPlayback;
/// 回放开关
@property (nonatomic, strong, readonly) NSString *playBackEnabled;
/// 观众举手示意开关，默认为N 关闭
@property (nonatomic, strong, readonly) NSString *viewerSignalEnabled;
/// 奖励观众奖杯开关，默认为N 关闭
@property (nonatomic, strong, readonly) NSString *awardTrophyEnabled;
/// rtc类型
@property (nonatomic, strong, readonly) NSString *rtcType;

@end
