//
//  BCLManager.h
//  BeacrewLoco
//
//  Created by Yukio Sekimoto on 2016/10/25.
//  Copyright (c) 2016 Beacrew Inc. All rights reserved.
//

#ifndef BeacrewLoco_BCLManager_h
#define BeacrewLoco_BCLManager_h

#import <BeacrewLoco/BCLAction.h>
#import <BeacrewLoco/BCLBeacon.h>
#import <BeacrewLoco/BCLCluster.h>
#import <BeacrewLoco/BCLError.h>
#import <BeacrewLoco/BCLRegion.h>
#import <Foundation/Foundation.h>

/**
 SDKの初期化ステータスを表します。
 */
typedef NS_ENUM(NSUInteger, BCLInitState) {
    /**
     不明
     */
    BCLInitStateUnknown,
    /**
     初期化中
     */
    BCLInitStateInitializing,
    /**
     初期化完了
     */
    BCLInitStateReady,
    /**
     エラー発生
     */
    BCLInitStateError
};

/**
 BCLManagerイベント受信デリゲート
 */
@protocol BCLManagerDelegate <NSObject>

@optional

/**
 デリゲートへビーコンのレンジング結果を伝えます。
 @param beacons 受信したビーコンのリスト
 */
- (void)didRangeBeacons:(NSArray<BCLBeacon *> *)beacons;

/**
 デリゲートへリージョン内へ入ったことを通知します。
 @param region 進入したリージョン情報
 */
- (void)didEnterRegion:(BCLRegion *)region;

/**
 デリゲートへリージョンから出たことを通知します。
 @param region 退出したリージョン情報
 */
- (void)didExitRegion:(BCLRegion *)region;

/**
 デリゲートへアクションの発生を通知します。
 @param action アクション情報
 */
- (void)didActionCalled:(BCLAction *)action;

/**
 デリゲートへ初期化ステータスに変化があったことを通知します。
 @param status 初期化ステータス
 */
- (void)didChangeInitStatus:(BCLInitState)status;

/**
 デリゲートへエラーが発生したことを通知します。
 @param error エラー内容
 */
- (void)didFailWithError:(BCLError *)error;

@end

/**
 LocoSDKを統括するクラスです。
 */
@interface BCLManager : NSObject

/**
 イベント受信デリゲートオブジェクト
 */
@property (weak, nonatomic) id<BCLManagerDelegate> delegate;
/**
 初期化ステータス
 */
@property (readonly, nonatomic) BCLInitState state;

/**
 Bluetooth設定がオフの場合に変更を促すダイアログを表示するかどうかを設定します。
 表示を抑制したい場合はsharedManagerを呼ぶ前にこのメソッドでNOを指定して下さい。
 デフォルト値はYESとなっています。
 @param show ダイアログ表示フラグ
 */
+ (void)showBluetoothDialog:(BOOL)show;

/**
 BCLMangerのシングルトンなインスタンスを取得します。
 */
+ (BCLManager *)sharedManager;

/**
 LocoSDKのイニシャライズを行います。
 @param apikey APIキー
 @param autoScan 自動スキャンフラグ trueをセットした場合、初期化後にスキャンが自動的に開始します。
 */
- (void)initWithApiKey:(NSString *)apikey autoScan:(BOOL)autoScan;

/**
 スキャンの開始を行います。
 */
- (void)scanStart;

/**
 スキャンの停止を行います。
 */
- (void)scanStop;

/**
 システムから割り当てられたデバイスのIDを取得します。
 @return デバイスID
 */
- (NSString *)getDeviceId;

/**
 システムから取得した登録リージョンのリストを取得します。
 @return 登録リージョンリスト
 */
- (NSArray<BCLRegion *> *)getRegions;

/**
 システムから取得した登録クラスタのリストを取得します。
 @return 登録クラスタリスト
 */
- (NSArray<BCLCluster *> *)getClusters;

/**
 システムから取得した登録ビーコンのリストを取得します。
 @return 登録ビーコンリスト
 */
- (NSArray<BCLBeacon *> *)getBeacons;

/**
 システムから取得した登録アクションのリストを取得します。
 @return 登録アクションリスト
 */
- (NSArray<BCLAction *> *)getActions;

/**
 現在の位置から最も近いビーコンのIDを取得します。
 @return ビーコンID
 */
- (NSString *)getNearestBeaconId;

/**
 ビーコンの検出ログを保持する件数を取得します。
 @return ビーコンログ保持件数
 */
- (NSInteger)getBeaconLogBufferSize;

/**
 ビーコンの検出ログを保持する件数を設定します。
 @param size ビーコンログ保持件数（設定できる範囲は1000〜100000件の間となります）
 */
- (void)setBeaconLogBufferSize:(NSInteger)size;

/**
 リージョンの検出ログを保持する件数を取得します。
 @return リージョンログ保持件数
 */
- (NSInteger)getRegionLogBufferSize;

/**
 リージョンの検出ログを保持する件数を設定します。
 @param size リージョンログ保持件数（設定できる範囲は1000〜100000件の間となります）
 */
- (void)setRegionLogBufferSize:(NSInteger)size;

/**
 イベント検出ログを保持する件数を取得します。
 @return イベントログ保持件数
 */
- (NSInteger)getEventLogBufferSize;

/**
 イベントログを保持する件数を設定します。
 @param size イベントログ保持件数（設定できる範囲は1000〜100000件の間となります）
 */
- (void)setEventLogBufferSize:(NSInteger)size;

/**
 ビーコンの検出ログを送信する間隔を取得します。
 @return ビーコンログ送信間隔（秒）
 */
- (NSInteger)getBeaconLogInterval;

/**
 ビーコンの検出ログを送信する間隔を設定します。
 @param interval ビーコンログ送信間隔（設定できる範囲は1〜3600秒の間となります）
 */
- (void)setBeaconLogInterval:(NSInteger)interval;

/**
 リージョンの検出ログを送信する間隔を取得します。
 @return リージョンログ送信間隔（秒）
 */
- (NSInteger)getRegionLogInterval;

/**
 リージョンの検出ログを送信する間隔を設定します。
 @param interval リージョンログ送信間隔（設定できる範囲は1〜3600秒の間となります）
 */
- (void)setRegionLogInterval:(NSInteger)interval;

/**
 イベントログを送信する間隔を取得します。
 @return イベントログ送信間隔（秒）
 */
- (NSInteger)getEventLogInterval;

/**
 イベントログを送信する間隔を設定します。
 @param interval イベントログ送信間隔（設定できる範囲は1〜3600秒の間となります）
 */
- (void)setEventLogInterval:(NSInteger)interval;

/**
 イベントログを追加します。
 @param key イベントキー（最大255文字。255文字を超えた分はカットされます）
 @param value イベント値（最大255文字。255文字を超えた分はカットされます）
 @return key、valueに値がセットされていない場合false、それ以外の場合はtrueが返されます。
 */
- (BOOL)addEventLog:(NSString *)key value:(NSString *)value;

@end

#endif
