//
//  BCLParam.h
//  BeacrewLoco
//
//  Created by Yukio Sekimoto on 2017/02/16.
//  Copyright (c) 2017 Beacrew Inc. All rights reserved.
//

#ifndef BeacrewLoco_BCLParam_h
#define BeacrewLoco_BCLParam_h

#import <Foundation/Foundation.h>

/**
 パラメータ情報を保持するクラスです。
 */
@interface BCLParam : NSObject

/**
 パラメータのキー
 */
@property NSString *key;

/**
 パラメータの値
 */
@property NSString *value;

@end

#endif
