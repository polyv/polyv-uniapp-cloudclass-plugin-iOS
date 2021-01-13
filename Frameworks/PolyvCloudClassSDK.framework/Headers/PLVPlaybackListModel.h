//
//  PLVPlaybackListModel.h
//  PolyvCloudClassSDK
//
//  Created by ftao on 2020/8/11.
//  Copyright © 2020 polyv. All rights reserved.
//
// 参考链接：
// https://dev.polyv.net/2017/liveproduct/l-api/zbglgn/lzhf/getplaybacklist/

#import <Foundation/Foundation.h>
#import <PolyvFoundationSDK/PLVSafeModel.h>

@interface PLVPlaybackVideoModel : PLVSafeModel

/// 是否为默认播放视频，值为Y/N
@property (nonatomic, copy) NSString *asDefault;
/// 回放视频对应的直播频道id
@property (nonatomic, copy) NSString *channelId;
/// 用于PPT请求数据，与PPT直播的回放相关，普通直播回放值为null
@property (nonatomic, copy) NSString *channelSessionId;
/// 视频长度
@property (nonatomic, copy) NSString *duration;
/// 视频首图
@property (nonatomic, copy) NSString *firstImage;
/// 视频合并信息，后续补充
@property (nonatomic, copy) NSString *mergeinfo;
/// 默认视频的播放清晰度，1为流畅，2为高清，3为超清
@property (nonatomic, copy) NSString *myBr;
/// 访客信息收集id
@property (nonatomic, copy) NSString *qid;
/// 视频加密状态，1表示为加密状态，0为非加密
@property (nonatomic, assign) long seed;
/// 直播开始时间
@property (nonatomic, copy) NSString *startTime;
/// 视频标题
@property (nonatomic, copy) NSString *title;
/// 视频播放地址，注：如果视频为加密视频，则此地址无法访问
@property (nonatomic, copy) NSString *url;
/// 点播后台用户id
@property (nonatomic, copy) NSString *userId;
/// 直播系统生成的id
@property (nonatomic, copy) NSString *videoId;
/// 点播视频vid
@property (nonatomic, copy) NSString *videoPoolId;
/// 直播类型
@property (nonatomic, copy) NSString *liveType;
/// 添加为回放视频的日期
@property (nonatomic, copy) NSString *createdTime;
/// 视频最后修改日期
@property (nonatomic, copy) NSString *lastModified;

@end

@interface PLVPlaybackListModel : PLVSafeModel

/// 回放视频总个数
@property (nonatomic, assign) long totalItems;
/// 总页数
@property (nonatomic, assign) long totalPages;
/// 当前页第一个视频在回放视频中的位置
@property (nonatomic, assign) long startRow;
/// 当前页最后一个视频在回放视频中的位置
@property (nonatomic, assign) long endRow;
/// 是否为第一页，值为：true/false
@property (nonatomic, assign) BOOL firstPage;
/// 是否为最后一页，值为：true/false
@property (nonatomic, assign) BOOL lastPage;
/// 上一页编号
@property (nonatomic, assign) long prePageNumber;
/// 下一页编号
@property (nonatomic, assign) long nextPageNumber;
/// 当前页视频个数
@property (nonatomic, assign) long limit;
/// 视频列表页数（默认以12条数据为1页）
@property (nonatomic, assign) long pageNumber;

/// 视频列表
@property (nonatomic, copy) NSArray<PLVPlaybackVideoModel *> *contents;

@end
