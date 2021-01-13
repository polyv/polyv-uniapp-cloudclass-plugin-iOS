//
//  PLVFBaseLogReporter.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/11/27.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PLVFLogModel;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PLVFLogProductType) {
    PLVProductTypeVod = 0, /// 点播
    PLVProductTypeLive,    /// 云课堂观看
    PLVProductTypeStreamer /// 手机开播
};

@interface PLVFBaseLogReporter : NSObject

@property (nonatomic, assign) PLVFLogProductType productType;

- (void)reportModel:(PLVFLogModel *)model;

@end

NS_ASSUME_NONNULL_END
