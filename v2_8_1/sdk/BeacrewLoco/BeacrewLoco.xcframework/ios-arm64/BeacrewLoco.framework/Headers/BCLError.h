//
//  BCLError.h
//  BeacrewLoco
//
//  Created by Yukio Sekimoto on 2016/11/02.
//  Copyright (c) 2016 Beacrew Inc. All rights reserved.
//

#ifndef BeacrewLoco_BCLError_h
#define BeacrewLoco_BCLError_h

#import <Foundation/Foundation.h>

/**
 エラーの情報を保持するクラスです。
 */
@interface BCLError : NSObject

/**
 エラーコード
 */
@property NSInteger code;

/**
 エラーメッセージ
 */
@property NSString *message;

/**
 エラー詳細（詳細情報が無い場合はnilが入ります）
 */
@property NSError *detail;

@end

#endif
