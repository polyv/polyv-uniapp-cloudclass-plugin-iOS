//
//  PLVFViewLogModel.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/12/23.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <PolyvFoundationSDK/PolyvFoundationSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVFViewLogModel : PLVFLogModel

/// 直播独有属性
/// 频道ID，直播独有属性
@property (nonatomic, copy) NSString *cid;

/// 点播独有属性
/// 视频ID，点播独有属性
@property (nonatomic, copy) NSString *vid;
/// 发送统计数据时，视频播放的时间位置，单位：秒，点播独有属性
@property (nonatomic, strong) NSString *cts;
/// 视频的时长，单位：秒，点播独有属性
@property (nonatomic, strong) NSNumber *duration;
/// 分类id，即视频是属于哪个分类的，点播独有属性
@property (nonatomic, strong) NSNumber *cataid;
/// 用户自定义的观众/学员ID，UrlSafeBase64编码，点播独有属性
@property (nonatomic, copy) NSString *sid;
/// 观众/学员头像的url地址，UrlSafeBase64编码，点播独有属性
@property (nonatomic, copy) NSString *viewerAvatar;
/// 子账号ID，点播独有属性
@property (nonatomic, copy) NSString *appId;

/// 播放器为每次播放产生的唯一ID
@property (nonatomic, copy) NSString *pid;

/// 用户ID，即视频是属于那个用户的
@property (nonatomic, copy) NSString *uid;

/// 本次播放累积加载流量大小，单位：bytes
@property (nonatomic, strong) NSNumber *flow;

/// 视频播放时长，观众真实观看的累计时长，单位：秒
@property (nonatomic, strong) NSNumber *pd;

/// 停留时长，播放器加载完成后开始计算，单位：秒
@property (nonatomic, strong) NSNumber *sd;

/// 视频所在的页面播放地址，UrlSafeBase64编码
@property (nonatomic, strong) NSString *href;

/// 播放器或SDK的名字，例如：flash
@property (nonatomic, strong) NSString *pn;

/// 播放器或SDK的版本号，例如：1.0.2-20170327
@property (nonatomic, strong) NSString *pv;

/// 播放场次ID，UrlSafeBase64编码，从channel json中的channelSessionId字段获取
@property (nonatomic, copy) NSString *session_id;

/// 自定义参数1，UrlSafeBase64编码 (直播：统计后台用户ID)
@property (nonatomic, copy) NSString *param1;

/// 自定义参数2，UrlSafeBase64编码 (统计后台观众昵称)
@property (nonatomic, copy) NSString *param2;

/// 自定义参数3，UrlSafeBase64编码 (直播/回放：值是live/vod)
@property (nonatomic, copy) NSString *param3;

/// 自定义参数4，UrlSafeBase64编码
@property (nonatomic, copy) NSString *param4;

/// 自定义参数5，UrlSafeBase64编码
@property (nonatomic, copy) NSString *param5;

/// 自定义业务索引1，UrlSafeBase64编码
@property (nonatomic, copy) NSString *key1;

/// 自定义业务索引2，UrlSafeBase64编码
@property (nonatomic, copy) NSString *key2;

/// 自定义业务索引3，UrlSafeBase64编码
@property (nonatomic, copy) NSString *key3;

/// 通用跟踪事件：
/// bop (beginning of play) 代表是本次观看的首条viewlog
/// pop (pause of play) 代表观看过程的一次暂停
/// rop (resume of play) 代表暂停后恢复播放
/// mt (mute) 开启静音
/// umt (unmute) 关闭静音
@property (nonatomic, copy) NSString *ute;

/// UrlSafeBase64编码，用于传自定义事件的各种数据，有多个值时用 ”|“ 号分割
@property (nonatomic, copy) NSString *uted;

@end

NS_ASSUME_NONNULL_END
