//
//  PLVLiveDefine.h
//  PolyvCloudClassSDK
//
//  Created by zykhbl on 2018/7/27.
//  Copyright © 2018年 polyv. All rights reserved.
//

#ifndef PLVLiveDefine_h
#define PLVLiveDefine_h

/// 直播状态
typedef NS_ENUM(NSInteger, PLVLiveStreamState) {
    /// 直播流状态未知
    PLVLiveStreamStateUnknown   = -1,
    /// 无直播流
    PLVLiveStreamStateNoStream  = 0,
    /// 直播中
    PLVLiveStreamStateLive      = 1,
    /// 直播暂停（stop为后台数据标识）
    PLVLiveStreamStateStop      = 2
};

#endif /* PLVLiveDefine_h */
