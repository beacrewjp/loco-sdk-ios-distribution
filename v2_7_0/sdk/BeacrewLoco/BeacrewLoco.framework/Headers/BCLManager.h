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
 SDKの内部ステータスを表します。
 */
typedef NS_ENUM(NSUInteger, BCLState) {
    /**
     未初期化
     */
    BCLStateUninitialized,
    /**
     初期化中
     */
    BCLStateInitializing,
    /**
     初期化完了
     */
    BCLStateReady,
    /**
     スキャン中
     */
    BCLStateScanning,
    /**
     エラー発生
     */
    BCLStateError
};

/**
 BCLManagerイベント受信デリゲート
 */
@protocol BCLManagerDelegate <NSObject>

@optional

/**
 デリゲートへアクションの発生を通知します。
 @param action 発生したアクションの情報
 @param type アクションのタイプを示す文字列　ビーコン検知での発生の場合"Beacon"が、リージョン進入による場合"RegionIn"が、リージョン退出の場合"RegionOut"がセットされます。
 @param source アクションの発生要因　ビーコン検知で発生した場合ビーコンの情報がBCLBeacon型で、リージョン進入・退出で発生した場合リージョンの情報がBCLRegion型で格納されます。
 */
- (void)didActionCalled:(BCLAction *)action type:(NSString *)type source:(id)source;

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
 デリゲートへSDK内部ステータスに変化があったことを通知します。
 @param status SDK内部ステータス
 */
- (void)didChangeStatus:(BCLState)status;

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
 SDK内部ステータス
 */
@property (readonly, nonatomic) BCLState state;

/**
 Bluetooth設定がオフの場合に変更を促すダイアログを表示するかどうかを設定します。
 表示を抑制したい場合はsharedManagerを呼ぶ前にこのメソッドでNOを指定して下さい。
 デフォルト値はYESとなっています。
 @param show ダイアログ表示フラグ
 */
+ (void)showBluetoothDialog:(BOOL)show;

/**
 Realmのマイグレーション時にrealmファイルを削除するかどうかを設定します。
 LocoSDKではRealmをデータベースとして使用していますが、お客様でもRealmを使用していた場合、スキーマ定義が双方のrealmファイルに入ってしまいマイグレーション処理が上手くいかなくなる場合が有ります。
 その様な場合にはsharedManagerを呼ぶ前にこのメソッドでYESを指定する事により、LocoSDKで使用するrealmファイルが削除され、クリーンな状態にデータベースが初期化されます。
 デフォルト値はNOとなっています。
 @param yesno 削除処理実行フラグ
 */
+ (void)deleteRealmIfMigrationNeeded:(BOOL)yesno;

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
 システムから取得した登録リージョンを指定した条件で絞り込んだリストを取得します。
 条件にはNSDictionaryへkeyにBCLRegionのメンバ名、valueに絞り込みたい値を文字列で設定して下さい。複数設定する事も可能です。
 @param condition 絞り込み条件
 @return 絞り込みを行なった登録リージョンのリスト
 */
- (NSArray<BCLRegion *> *)getRegionByCondition:(NSDictionary *)condition;

/**
 システムから取得した登録クラスタのリストを取得します。
 @return 登録クラスタリスト
 */
- (NSArray<BCLCluster *> *)getClusters;

/**
 システムから取得した登録クラスタを指定した条件で絞り込んだリストを取得します。
 条件にはNSDictionaryへkeyにBCLClusterのメンバ名、valueに絞り込みたい値を文字列で設定して下さい。複数設定する事も可能です。
 @param condition 絞り込み条件
 @return 絞り込みを行なった登録クラスタのリスト
 */
- (NSArray<BCLCluster *> *)getClusterByCondition:(NSDictionary *)condition;

/**
 システムから取得した登録ビーコンのリストを取得します。
 @return 登録ビーコンリスト
 */
- (NSArray<BCLBeacon *> *)getBeacons;

/**
 システムから取得した登録ビーコンを指定した条件で絞り込んだリストを取得します。
 条件にはNSDictionaryへkeyにBCLBeaconのメンバ名、valueに絞り込みたい値を文字列で設定して下さい。複数設定する事も可能です。
 @param condition 絞り込み条件
 @return 絞り込みを行なった登録ビーコンのリスト
 */
- (NSArray<BCLBeacon *> *)getBeaconByCondition:(NSDictionary *)condition;

/**
 システムから取得した登録アクションのリストを取得します。
 @return 登録アクションリスト
 */
- (NSArray<BCLAction *> *)getActions;

/**
 システムから取得した登録アクションを指定した条件で絞り込んだリストを取得します。
 条件にはNSDictionaryへkeyにBCLActionのメンバ名、valueに絞り込みたい値を文字列で設定して下さい。複数設定する事も可能です。
 @param condition 絞り込み条件
 @return 絞り込みを行なった登録アクションのリスト
 */
- (NSArray<BCLAction *> *)getActionByCondition:(NSDictionary *)condition;

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

/**
 デバイスログを追加します。
 @param metadata デバイスログに付加するメタデータ
 */
- (void)addDeviceLog:(NSString *)metadata;

@end

#endif
