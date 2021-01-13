//
//  PLVTriviaCardViewController.h
//  PolyvCloudClassSDK
//
//  Created by zykhbl on 2018/9/3.
//  Copyright © 2018年 polyv. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PolyvBusinessSDK/PolyvBusinessSDK.h>

@class PLVTriviaCardViewController;

@protocol PLVTriviaCardViewControllerDelegate <NSObject>

@optional

/// 学员签到回调
- (void)triviaCardViewController:(PLVTriviaCardViewController *)triviaCardVC checkIn:(NSDictionary *)dict;

/// 答题卡选择答题时回调
- (void)triviaCardViewController:(PLVTriviaCardViewController *)triviaCardVC chooseAnswer:(NSDictionary *)dict;

/// 问卷提交时回调
- (void)triviaCardViewController:(PLVTriviaCardViewController *)triviaCardVC questionnaireAnswer:(NSDictionary *)dict;

/// 抽奖回调
- (void)triviaCardViewController:(PLVTriviaCardViewController *)triviaCardVC lottery:(NSDictionary *)dict;

/// 点击公告链接回调
- (void)triviaCardViewController:(PLVTriviaCardViewController *)triviaCardVC clickLink:(NSURL *)linkURL;

@end

/**
 H5页面控制器（互动功能）
 */
@interface PLVTriviaCardViewController : UIViewController

/// delegate
@property (nonatomic, weak) id<PLVTriviaCardViewControllerDelegate> delegate;

/// 定制的本地答题卡静态页面地址（如果不为nil，答题卡w加载静态html；为nil时，加载默认服务器的html）
@property (nonatomic, strong) NSString *localHtml;

@property (nonatomic, strong) NSURL *baseURL;
/// 互动页面关闭按钮（webview加载成功后将自动隐藏；可自定义按钮图标）
@property (nonatomic, strong, readonly) UIButton *closeBtn;

/// 视图布局
- (void)layout:(BOOL)fullscreen;

#pragma mark 通用

/// 提交结果回传
- (void)submitResultCallback:(NSString *)json event:(NSString *)event;

/// 提交结果超时回传
- (void)submitResultTimeoutCallback:(NSString *)event;

#pragma mark 公告功能

/// 加载公告
- (void)openBulletin:(NSString *)json;

/// 打开最新的公告
- (void)openLastBulletin;

/// 删除公告
- (void)removeBulletin;

#pragma mark 签到功能

/// 发起签到
- (void)startSign:(NSString *)json;

/// 停止签到
- (void)stopSign:(NSString *)json;

#pragma mark 答题卡功能

/// 加载答题卡题目信息
- (void)openQuestionContent:(NSString *)json;

/// 公布答题卡答案和作答详情
- (void)openQuestionResult:(NSString *)json;

/// 测试答题卡
- (void)testQuestion:(NSString *)json;

#pragma mark 问卷功能

/// 发起问卷
- (void)openQuestionnaireContent:(NSString *)json;

/// 停止问卷
- (void)stopQuestionNaire:(NSString *)json;

/// 观看端接收到问卷结果
- (void)sendQuestionNaireResult:(NSString *)json;

/// 观看端接收到问卷统计相关数据事件
- (void)questionNaireAchievement:(NSString *)json;

#pragma mark 抽奖功能

/// 发起抽奖
- (void)startLottery:(NSString *)json;

/// 停止抽奖
- (void)stopLottery:(NSString *)json socketIO:(PLVSocketIO *)socketIO;

@end
