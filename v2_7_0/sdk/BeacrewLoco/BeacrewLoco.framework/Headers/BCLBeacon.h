//
//  BCLBeacon.h
//  BeacrewLoco
//
//  Created by Yukio Sekimoto on 2016/11/22.
//  Copyright (c) 2016 Beacrew Inc. All rights reserved.
//

#ifndef BeacrewLoco_BCLBeacon_h
#define BeacrewLoco_BCLBeacon_h

#import <Foundation/Foundation.h>
#import <BeacrewLoco/BCLAction.h>

/**
 ビーコンの情報を保持するクラスです。
 */
@interface BCLBeacon : NSObject

/**
 ビーコンID
 */
@property NSString *beaconId;

/**
 ビーコン名
 */
@property NSString *name;

/**
 ビーコンのUUID
 */
@property NSString *uuid;

/**
 ビーコンのmajor番号
 */
@property NSInteger major;

/**
 ビーコンのminor番号
 */
@property NSInteger minor;

/**
 ビーコンのTxPower
 */
@property NSInteger txPower;

/**
 ビーコンのRSSI
 */
@property NSInteger rssi;

/**
 ビーコンのローカルネーム
 */
@property NSString *localName;

/**
 ビーコンのモジュールID
 */
@property NSString *moduleId;

/**
 ビーコンのモデル
 */
@property NSString *model;

/**
 ビーコンのメーカー
 */
@property NSString *manufacturer;

/**
 ビーコンのX座標
 */
@property NSInteger x;

/**
 ビーコンのY座標
 */
@property NSInteger y;

/**
 ビーコンの設置高
 */
@property NSInteger height;

/**
 ビーコンに紐付いているアクションのリスト
 */
@property NSArray<BCLAction *> *actions;

@end

#endif
