//
//  PLVJSBridge.h
//  PolyvFoundationSDK
//
//  Created by zykhbl on 2018/9/3.
//  Copyright © 2018年 polyv. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import <JavaScriptCore/JavaScriptCore.h>

@class PLVJSBridge;

@protocol PLVJSBridgeDelegate <NSObject>

@optional

- (void)didFinishLoad:(PLVJSBridge *)jsBridge;

- (void)didFailLoad:(PLVJSBridge *)jsBridge;

@end

@interface PLVJSBridge : NSObject

@property (nonatomic, weak) id<PLVJSBridgeDelegate> delegate;

@property (nonatomic, weak) NSObject *jsExport;

@property (nonatomic, strong) NSArray *jsFunctions;

@property (nonatomic, strong) WKWebView *webView;

@property (nonatomic, assign) BOOL webviewLoadFinish;

@property (nonatomic, assign) BOOL webviewLoadFaid;

- (void)loadWebView:(NSString *)url inView:(UIView *)view;

- (void)loadHTMLString:(NSString *)html baseURL:(NSURL *)baseURL inView:(UIView *)view;

- (void)call:(NSString *)jsFunction params:(NSArray *)params;

- (void)destruct;

@end
