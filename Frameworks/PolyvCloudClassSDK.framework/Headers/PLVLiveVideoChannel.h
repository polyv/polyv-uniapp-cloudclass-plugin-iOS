//
//  PLVLiveVideoChannel.h
//  PolyvCloudClassSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 频道限制信息
typedef NS_ENUM(NSInteger, PLVLiveRestrictState) {
    /// 未知（获取失败）
    PLVLiveRestrictUnknown = -1,
    /// 无限制（可正常播放）
    PLVLiveRestrictNone    = 0,
    /// 限制播放（不可播放）
    PLVLiveRestrictPlay    = 1,
};

/// 暖场类型
typedef NS_ENUM(NSUInteger, PLVLiveCoverType) {
    /// 无暖场
    PLVLiveCoverTypeNone,
    /// 图片类型
    PLVLiveCoverTypeImage,
    /// 视频类型
    PLVLiveCoverTypeVideo,
};

/// 跑马灯类型
typedef NS_ENUM(NSUInteger, PLVLiveMarqueeType) {
    /// 无
    PLVLiveMarqueeTypeNone,
    /// 固定类型
    PLVLiveMarqueeTypeFixed,
    /// 登录用户名
    PLVLiveMarqueeTypeNick,
    /// URL自定义
    PLVLiveMarqueeTypeURL,
};

/// 直播观看频道信息
@interface PLVLiveVideoChannel : NSObject

/// 直播频道Id
@property (nonatomic, copy, readonly) NSNumber *channelId;
/// 云直播账号 用户Id
@property (nonatomic, copy, readonly) NSString *userId;
/// 直播场次
@property (nonatomic, copy, readonly) NSString *sessionId;
/// 直播频道名称
@property (nonatomic, copy, readonly) NSString *name;
/// 直播流名
@property (nonatomic, copy, readonly) NSString *stream;
/// 流类型（disk为硬盘推流）
@property (nonatomic, copy, readonly) NSString *streamType;

/// 多码率是否开启
@property (nonatomic, assign, readonly) BOOL isMultirateEnabled;
/// 默认清晰度，多码率开启时使用
@property (nonatomic, copy, readonly) NSString *defaultDefinition;
/// 默认清晰度地址，多码率开启时使用
@property (nonatomic, copy, readonly) NSString *defaultDefinitionUrl;
/// 默认音频地址
@property (nonatomic, copy, readonly) NSString *defaultAudioUrl;
/// 所有清晰度，多码率开启时使用
@property (nonatomic, copy, readonly) NSArray<NSDictionary *> *definitions;

/// 直播多线路地址
@property (nonatomic, copy, readonly) NSArray<NSDictionary *> *lines;

/// 直播限制状态
@property (nonatomic, assign, readonly) PLVLiveRestrictState restrictState;
/// 限制信息：restrictState Unknown 时为 nil
@property (nonatomic, copy, readonly) NSDictionary *restrictInfo;

/// 暖场类型
@property (nonatomic, assign, readonly) PLVLiveCoverType coverType;
/// 暖场资源地址
@property (nonatomic, copy, readonly) NSString *coverUrl;
/// 图片类型暖场的跳转链接(可能为nil)
@property (nonatomic, copy, readonly) NSString *coverHref;

/// Qos 发送频率
@property (nonatomic, copy, readonly) NSNumber *reportFreq;

/// 跑马灯信息
@property (nonatomic, copy) NSString *marquee;                    // TypeDefault：跑马灯内容；TypeURL：自定义地址
@property (nonatomic, readonly) PLVLiveMarqueeType marqueeType;   // 跑马灯类型
@property (nonatomic, copy, readonly) NSNumber *marqueeFontSize;  // 字体大小
@property (nonatomic, copy, readonly) NSString *marqueeFontColor; // 字体颜色
@property (nonatomic, copy, readonly) NSString *marqueeOpacity;   // 透明度
@property (nonatomic, readonly) BOOL marqueeAutoZoomEnabled;      // 自定义缩放

@property (nonatomic, readonly) BOOL closeDanmuEnable;      // 弹幕模块是否启用

/**
 便利初始化方法
 */
+ (instancetype)liveChannelWithJsonDict:(NSDictionary *)jsonDict;

/**
 更新频道限制信息（异步）
 
 @param completion 请求完成
 */
- (void)updateChannelRestrictInfo:(void (^)(void))completion;

/**
 更新默认清晰度

 @param definition 清晰度
 */
- (NSArray *)updateDefaultDefinitionWithDefinition:(NSString *)definition lineIndex:(NSUInteger)lineIndex;

@end
