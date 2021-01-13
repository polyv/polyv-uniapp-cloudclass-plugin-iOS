//
//  PLVFFileUtil.h
//  PolyvFoundationSDK
//
//  Created by MissYasiky on 2019/12/4.
//  Copyright © 2019 polyv. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PLVFFileUtil : NSObject

+ (NSString *)homePath;

+ (NSString *)documentPath;

+ (NSString *)libraryPath;

+ (NSString *)cachesPath;

+ (NSString *)tempPath;

+ (BOOL)createFileAtPath:(NSString *)filePath;

+ (BOOL)deleteFileAtPath:(NSString *)filePath;

+ (BOOL)writeData:(NSData *)data atPath:(NSString *)filePath;

+ (NSData *)dataAtPath:(NSString *)filePath;

@end

NS_ASSUME_NONNULL_END
