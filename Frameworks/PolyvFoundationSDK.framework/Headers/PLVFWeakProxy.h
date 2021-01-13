//
//  PLVFWeakProxy.h
//  PolyvFoundationSDK
//
//  Created by Lincal on 2020/7/30.
//  Copyright © 2020 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 弱引用代理类
///
/// @note 用于解决某些系统方法会强制持有 self，导致不自动释放，而不走dealloc的问题
///
/// @code
/// // 创建 Timer 时，以 weakProxy 作为 target 参数
/// PLVFWeakProxy * weakProxy = [PLVFWeakProxy proxyWithTarget:self];
/// _timer = [NSTimer scheduledTimerWithTimeInterval:1.0 target:weakProxy selector:@selector(timerEvent:) userInfo:nil repeats:NO];
///
/// // 则 dealloc 会正常被调用，并可在此时对 Timer 进行释放
/// - (void)dealloc{
///    [_timer invalidate];
///    _timer = nil;
/// }
/// @endcode
///
@interface PLVFWeakProxy : NSProxy

/// 当前被替代的对象
///
/// @note 事件将仍然触发该target对象
@property (nonatomic, weak, readonly, nullable) id target;

/// 创建 weakProxy 弱引用代理对象 (对象方法)
///
/// @param target 需要替代的对象
- (nonnull instancetype)initWithTarget:(nonnull id)target;

/// 创建 weakProxy 弱引用代理对象 (类方法)
///
/// @param target 需要替代的对象
+ (nonnull instancetype)proxyWithTarget:(nonnull id)target;

@end

NS_ASSUME_NONNULL_END
