//
//  PLVDataUtil.h
//  PolyvNetworkSDK
//
//  Created by zykhbl on 2018/7/30.
//  Copyright © 2018年 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 只在SDK内部使用，不向外提供
 NSData数据处理通用工具类
 */
@interface PLVDataUtil : NSObject

#pragma mark - MD5
/**
 MD5 加密方法
 
 @param input 待加密的字符串
 @return 32 位小写加密串
 */
+ (NSString *)md5HexDigest:(NSString *)input;

#pragma mark - 二进制/十六进制
/**
 二进制转十六进制
 
 @param data 二进制
 @return 十六进制字符串
 */
+ (NSString *)hexStringFromData:(NSData *)data;

/**
 十六进制字符串转二进制
 
 @param hexString 十六进制字符串
 @return 二进制
 */
+ (NSData *)dataForHexString:(NSString *)hexString;

#pragma mark - AES 128
/**
 AES 128 加密
 
 @param data 待加密的数据
 @param key key 值
 @param iv iv 向量值
 @return 加密后的 data 数据
 */
+ (NSData *)AES128EncryptData:(NSData *)data withKey:(NSString *)key iv:(NSString *)iv;

/**
 AES 128 解密
 
 @param data 待解密数据
 @param key key 值
 @param iv iv 向量值
 @return 解密的 data 数据
 */
+ (NSData *)AES128DecryptData:(NSData *)data withKey:(NSString *)key iv:(NSString *)iv;

#pragma mark - URL SafeBase64

/**
 普通字符的URL safeBase64 编码
 
 @param string 待编码字符串
 @return 编码的 safeBase64 字符串
 */
+ (NSString *)safeUrlBase64Encode:(NSString *)string;

/**
 URL safeBase64 字符解码
 
 @param safeBase64Str 编码的 safeBase64 字符串
 @return data base64 数据
 */
+ (NSData *)safeUrlBase64Decode:(NSString *)safeBase64Str;

/// Base64 编码
+ (NSString *)base64String:(NSString *)inputString;

/// url safe Base64 编码
+ (NSString *)urlSafeBase64String:(NSString *)inputString;

/// SHA1 加密
+ (NSString *)sha1String:(NSString *)inputString;

/// AES-128 加密，不使用加密向量
+ (NSData *)AES128EncryptedDataWithKey:(NSString *)key data:(NSData *)data;

/// AES-128 解密，不使用加密向量
+ (NSData *)AES128DecryptedDataWithKey:(NSString *)key data:(NSData *)data;

/// AES-128 加密
+ (NSData *)AES128EncryptedDataWithKey:(NSString *)key iv:(NSString *)iv data:(NSData *)data;

/// AES-128 解密
+ (NSData *)AES128DecryptedDataWithKey:(NSString *)key iv:(NSString *)iv data:(NSData *)data;

+ (NSData *)AES128Operation:(uint32_t)operation key:(NSData *)keyData iv:(NSData *)ivData data:(NSData *)contentData;

/// 十六进制字符串转NSData
+ (NSData *)dataWithHexString:(NSString *)hexString;

@end
