//
//  PLVWebViewController.h
//  PolyvCloudClassDemo
//
//  Created by MissYasiky on 2019/9/19.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PLVWebViewTuwenProtocol <NSObject>

- (void)clickTuwenImage:(BOOL)showImage;

@end

@interface PLVWebViewController : UIViewController

@property (nonatomic, weak) id<PLVWebViewTuwenProtocol> tuwenDelegate;

- (void)loadURLString:(NSString *)urlString;

- (void)loadHtmlWithContent:(NSString *)content;

- (void)socketEvent:(NSString *)event data:(NSString *)json;

#pragma mark - 图文直播专用

- (void)setupTuwen:(NSUInteger)channelId;

- (void)reconnectTuwen;

@end

NS_ASSUME_NONNULL_END
