//
//  BCLRegion.h
//  BeacrewLoco
//
//  Created by Yukio Sekimoto on 2016/11/22.
//  Copyright (c) 2016 Beacrew Inc. All rights reserved.
//

#ifndef BeacrewLoco_BCLRegion_h
#define BeacrewLoco_BCLRegion_h

#import <Foundation/Foundation.h>
#import <BeacrewLoco/BCLAction.h>

/**
 リージョンの情報を保持するクラスです。
 */
@interface BCLRegion : NSObject

/**
 リージョンのID
 */
@property NSString *regionId;

/**
 リージョン名
 */
@property NSString *name;

/**
 リージョンのタイプ ビーコンリージョンの場合は"Beacon"が、ジオフェンスリージョンの場合は"Geofence"が入ります。
 */
@property NSString *type;

/**
 リージョンのUUID
 */
@property NSString *uuid;

/**
 リージョンのmajor番号
 */
@property NSNumber *major;

/**
 リージョンのminor番号
 */
@property NSNumber *minor;

/**
 リージョン中心点の緯度
 */
@property NSNumber *latitude;

/**
 リージョン中心点の軽度
 */
@property NSNumber *longitude;

/**
 リージョンの半径(m)
 */
@property NSNumber *radius;

/**
 リージョンイン時に発生するアクション
 */
@property NSArray<BCLAction *> *inAction;

/**
 リージョンアウト時に発生するアクション
 */
@property NSArray<BCLAction *> *outAction;

@end

#endif
