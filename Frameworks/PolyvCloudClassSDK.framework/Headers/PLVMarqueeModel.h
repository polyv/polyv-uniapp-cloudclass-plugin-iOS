//
//  PLVMarqueeModel.h
//  PolyvCloudClassSDK
//
//  Created by ftao on 2019/2/26.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, PLVMarqueeModelStyle) {
    /// 滚动（自屏幕右方至左方一直滚动）
    PLVMarqueeModelStyleRoll,
    /// 闪现（屏幕内随机位置闪烁）
    PLVMarqueeModelStyleFlash,
    /// 滚动+闪现（自屏幕右方至左方一直滚动，渐隐渐现）
    PLVMarqueeModelStyleRollFade,
    /// 局部滚动（上下15%的视频区域之间滚动）
    PLVMarqueeModelStylePartRoll,
    /// 局部闪现（上下15%的视频区域随机闪现文字）
    PLVMarqueeModelStylePartFlash,
};

@interface PLVMarqueeModel : NSObject

/// 跑马灯样式
@property (nonatomic, assign) PLVMarqueeModelStyle style;

/// 跑马灯内容
@property (nonatomic, strong) NSString *content;
/// 字体大小
@property (nonatomic, assign) NSUInteger fontSize;
/// 字体颜色（#000000）
@property (nonatomic, strong) NSString *fontColor;

/// 是否描边
@property (nonatomic, assign) BOOL filter;
/// 描边颜色（#000000）
@property (nonatomic, strong) NSString *filterColor;

/// 描边透明度（范围：0~1）
@property (nonatomic, assign) float filterAlpha;
/// 描边强度（范围：0~255）
@property (nonatomic, assign) NSUInteger strength;
/// 描边水平模糊量（范围：0~255）
@property (nonatomic, assign) NSUInteger blurX;
/// 描边垂直模糊量（范围：0~255）
@property (nonatomic, assign) NSUInteger blurY;

/// 文本透明度（范围：0~1）
@property (nonatomic, assign) float alpha;

/// 文字移动指定像素所需时间/显示时间（单位：秒）。有效样式：Roll、RollFade、PartRoll
@property (nonatomic, assign) NSUInteger speed;

/// 文本渐隐渐现时间 (单位：秒)。有效样式：RollFade
@property (nonatomic, assign) NSUInteger tweenTime;

/// 文本隐藏间隔时间 (单位：秒)。有效样式：Flash、PartFlash
@property (nonatomic, assign) NSUInteger interval;
/// 文本显示时间 (单位：秒)。有效样式：Flash、PartFlash
@property (nonatomic, assign) NSUInteger lifeTime;

/// 自定义缩放
@property (nonatomic, assign) BOOL autoZoom;

/**
 便利初始化模型（标准数据）

 @param content 跑马灯内容
 @param fontSize 字体大小
 @param fontColor 字体颜色（0x000000）
 @param alpha 文本透明度（范围：0~1）
 @param autoZoom 自定义缩放
 @return PLVMarqueeModel
 */
+ (instancetype)marqueeModelWithContent:(NSString *)content fontSize:(NSUInteger)fontSize fontColor:(NSString *)fontColor alpha:(float)alpha autoZoom:(BOOL)autoZoom;

/**
 便利初始化模型（自定义跑马灯数据）

 @param marqueeDict 跑马灯数据
 @return PLVMarqueeModel
 */
+ (instancetype)marqueeModelWithMarqueeDict:(NSDictionary *)marqueeDict;

/**
 根据模型内容动态生成属性字符串

 @return PLVMarqueeModel 的属性字符串文字
 */
- (NSAttributedString *)attributedContent;

/**
 根据模型内容计算size

 @return 内容大小
 */
- (CGSize)attributedContentSize;

@end
