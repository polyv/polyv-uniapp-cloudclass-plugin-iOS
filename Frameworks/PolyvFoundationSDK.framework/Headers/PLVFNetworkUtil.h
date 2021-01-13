//
//  PLVFNetworkUtil.h
//  PolyvFoundationSDK
//
//  Created by zykhbl on 2018/8/6.
//  Copyright © 2018年 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVNetworkError.h"

#define PLV_HM_POST     @"POST"
#define PLV_HM_GET      @"GET"
#define PLV_HM_DELETE   @"DELETE"

/**
 只在SDK内部使用，不向外提供
 网络请求通用工具类
 */
@interface PLVFNetworkUtil : NSObject

/**
 将键值参数拼成 HTTP 请求字符串
 
 @param params 请求参数：可为空，为 nil 时不设置请求参数
 @return HTTP 请求字符串
 */
+ (NSString*)paramStr:(NSDictionary *)params;

/**
 生成网络请求体
 
 @param url 请求地址
 @param params 请求参数：可为空，为 nil 时不设置请求参数
 @param httpMethod HTTP 请求方法，为 HM_POST 或者 HM_GET
 @param timeoutInterval 超时时长
 @param userAgent  User-Agent
 @return NSMutableURLRequest* 类型的网络请求体
 */
+ (NSMutableURLRequest *)requestWithURLString:(NSString *)url
                                       params:(NSDictionary *)params
                                   httpMethod:(NSString *)httpMethod
                              timeoutInterval:(NSTimeInterval)timeoutInterval
                                    userAgent:(NSString *)userAgent;

/**
 NSURLSession 异步网络请求数据
 
 @param request 请求体
 @param completion 请求完成回调代码块：服务器响应200时返回
 @param fail 请求失败回调代码块：请求失败或请求响应非200，以 error 参数是否为空区分
 */
+ (void)requestData:(NSURLRequest *)request
         completion:(void (^)(NSData *data, NSURLResponse *response))completion
               fail:(void (^)(NSError *error))fail;

/**
 NSURLSession 异步网络请求基础方法
 
 @param request 请求体
 @param completion 请求完成回调代码块：服务器响应200时返回
 @param fail 请求失败回调代码块：请求失败或请求响应非200，以 error 参数是否为空区分
 */
+ (void)requestNetwork:(NSURLRequest *)request
                 completion:(void (^)(NSDictionary *responseDict, NSArray *responseArr, NSString *responseCont))completion
                       fail:(void (^)(NSError *error))fail;

/**
 NSURLSession 异步网络请求字典
 
 @param request 请求体
 @param completion 请求完成返回字典回调代码块：服务器响应200时返回
 @param fail 请求失败回调代码块：请求失败或请求响应非200，以 error 参数是否为空区分
 */
+ (void)requestDictionary:(NSURLRequest *)request
               completion:(void (^)(NSDictionary *responseDict))completion
                     fail:(void (^)(NSError *error))fail;

/**
 NSURLSession 异步网络请求数组
 
 @param request 请求体
 @param completion 请求完成返回数组回调代码块：服务器响应200时返回
 @param fail 请求失败回调代码块：请求失败或请求响应非200，以 error 参数是否为空区分
 */
+ (void)requestArray:(NSURLRequest *)request
          completion:(void (^)(NSArray *responseArr))completion
                fail:(void (^)(NSError *error))fail;

/**
 NSURLSession 异步网络请求字符串
 
 @param request 请求体
 @param completion 请求完成返回字符串回调代码块：服务器响应200时返回
 @param fail 请求失败回调代码块：请求失败或请求响应非200，以 error 参数是否为空区分
 */
+ (void)requestString:(NSURLRequest *)request
           completion:(void (^)(NSString *responseCont))completion
                 fail:(void (^)(NSError *error))fail;

+ (void)fail:(void (^)(NSError *))fail
   errorCode:(PLVNetworkErrorCode)errorCode
        desc:(NSString*)desc;

+ (NSError *)failWitErrorCode:(PLVNetworkErrorCode)errorCode desc:(NSString*)desc;

@end
