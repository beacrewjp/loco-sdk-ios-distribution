//
//  BCLAction.h
//  BeacrewLoco
//
//  Created by Yukio Sekimoto on 2016/11/22.
//  Copyright (c) 2016 Beacrew Inc. All rights reserved.
//

#ifndef BeacrewLoco_BCLAction_h
#define BeacrewLoco_BCLAction_h

#import <Foundation/Foundation.h>
#import <BeacrewLoco/BCLParam.h>

/**
 アクションの情報を保持するクラスです。
 */
@interface BCLAction : NSObject

/**
 アクションID
 */
@property NSString *actionId;

/**
 アクションの名称
 */
@property NSString *name;

/**
 アクションのインターバル（秒）
 0の場合は毎回発火します。デフォルト値は0です。
 */
@property NSInteger interval;

/**
 アクションに紐づけられたURI文字列
 */
@property NSString *uri;

/**
 アクションに紐づけられたパラメータのリスト
 */
@property NSArray<BCLParam *> *params;

@end

#endif
