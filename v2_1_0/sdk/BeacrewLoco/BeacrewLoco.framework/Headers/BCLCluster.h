//
//  BCLCluster.h
//  BeacrewLoco
//
//  Created by Yukio Sekimoto on 2016/11/22.
//  Copyright (c) 2016 Beacrew Inc. All rights reserved.
//

#ifndef BeacrewLoco_BCLCluster_h
#define BeacrewLoco_BCLCluster_h

#import <Foundation/Foundation.h>
#import <BeacrewLoco/BCLBeacon.h>

/**
 クラスタの情報を保持するクラスです。
 */
@interface BCLCluster : NSObject

/**
 クラスタID
 */
@property NSString *clusterId;

/**
 親クラスタのID
 */
@property NSString *parentId;

/**
 クラスタ名
 */
@property NSString *name;

/**
 クラスタに設定されたタグ
 */
@property NSString *tag;

/**
 クラスタに設定された画像ファイル名
 */
@property NSString *image;

/**
 クラスタに所属するビーコンのリスト
 */
@property NSArray<BCLBeacon *> *beacons;

@end

#endif
