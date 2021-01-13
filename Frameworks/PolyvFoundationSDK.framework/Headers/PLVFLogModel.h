//
//  PLVFLogModel.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/12/5.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVFLogModel : NSObject

/// patch - 是否批量发送，
/// YES：批量发送，凑够 50 条才发送一次日志
/// NO：实时发送。
@property (nonatomic, assign) BOOL patch;

@end

NS_ASSUME_NONNULL_END
