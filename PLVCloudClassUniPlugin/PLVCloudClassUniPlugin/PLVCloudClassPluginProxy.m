//
//  PLVCloudClassPluginProxy.m
//  PLV-CloudClassUniPlugin
//
//  Created by ysh on 2020/11/12.
//

#import "PLVCloudClassPluginProxy.h"

@implementation PLVCloudClassPluginProxy

- (BOOL)application:(UIApplication *_Nullable)application didFinishLaunchingWithOptions:(NSDictionary *_Nullable)launchOptions {
    [[UIApplication sharedApplication] beginReceivingRemoteControlEvents];
    return YES;
}

/// 禁用第三方键盘，解决H5界面弹出第三方键盘时，界面不会往上推的问题（by CASE-30551）
- (BOOL)application:(UIApplication *)application shouldAllowExtensionPointIdentifier:(UIApplicationExtensionPointIdentifier)extensionPointIdentifier {
    if ([extensionPointIdentifier isEqualToString:UIApplicationKeyboardExtensionPointIdentifier]) {
        return NO;
    }
    return YES;
}

@end
