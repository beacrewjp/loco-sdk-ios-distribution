![](https://beacrew.jp/content/themes/child-theme/shared/img/service/loco/logo.png)
  
## LocoSDK iOS

### v2.9.0での変更点
v2.9.0では、SDKが自動生成するデバイスログを抑制する機能が追加されています
Locoダッシュボードのアプリ詳細画面の「テバイスログ設定 ( 生成タイプ / 生成間隔)」設定で「常に」、「1日1回」、「間を開けて」の３つからデバイスログが記録されるタイミングを選択する事ができます

常に：SDKの初期化時（initWithAPIKey実行時）に必ずデバイスログを記録します
1日1回：その日既にデバイスログを記録している場合は記録を行いません
間を開けて：最後にデバイスログを記録した日時より指定した分を経過するまで記録を行いません
v2.9.0では、同一のSDKバージョンのXCFrameworkをDynamicリンク版とStaticリンク版で配布を行っています
CocoaPodsでプロジェクトに導入する場合はDynamicリンク版が自動的に使用されます
SPM(Swift Package Manager)を使用してプロジェクトに導入する場合はご利用になるプロジェクトに合わせてDynamic版とStatic版を選択するようにして下さい

ご注意
v2.9.0ではXcodeバージョン26.4以降でのRealmのビルドエラーに対応する為、依存するRealmのバージョンをv20.0.4 以降に設定しております。ご利用になられる環境でv20.0.4 以前のバージョンのRealmを使用している場合はご相談下さい

### v2.8.2での変更点  
v2.8.2では、SPM(Swift Package Manager)でのプロジェクト取り込みに対応いたしました  
SDKの動作自体はv2.8.1と同じ物となっております  

### v2.8.2 ご利用時の注意
v2.8.2はSPMの標準的な動作に対応する為、Staticなフレームワークとしてビルドされております。依存ライブラリであるRealmも同時にインポートされるようにPackage.swiftを設定しておりますが、既にRealmをDynamicなフレームワークとしてEmbedして使用している場合、実行時に定義の重複によるエラーが発生する場合が有ります  

### v2.8.1での変更点  
v2.8.1では、SDKがxcframework化され、Apple Silicon端末でのarm64シミュレーターでのビルドに対応しています  

### v2.8.1 ご利用時の注意  
v2.8.1をcocoapod経由でインストールしてご使用になる場合、ビルド時に「Operation not permitted」が発生する場合が有ります  
これは、Xcode 14/15以降で強化されたセキュリティ設定（User Script Sandboxing）が原因である可能性が高いと思われますので、Xcodeの設定画面の Build Settings で「sandbox」を検索していただき、Build Options - User Script Sandboxing の値を No に変更していただくとビルドが通るようになるかと思います  
v2.8.1 は 近日中にSwift Package Manager（SPM）経由での配布を予定しています

### v2.8.0 ご利用時の注意  
  
v2.8.0をご使用になる場合、シミュレーター用バイナリはx86_64でのご利用になります  
※Apple Silicon搭載Macでご使用になる場合、シミュレーターはRosetta 2経由となります  
シミュレーターでのarm64バイナリのご利用は近日中にxcframeworkを利用した形式で公開予定です  
  
### Locoとは？
  
Locoは、お客様のアプリケーションにiBeaconを利用する為の機能を簡単に組み込む事が出来るサービスです。  
  
Loco管理画面からビーコンに関する設定を行い、SDKをお客様のアプリに組み込む事で、iBeaconを利用したチェックイン・屋内ナビゲーション・屋内位置測位・動線分析・ログ分析サービス構築の基盤がスピーディに準備できます。  
  
また、異なるOSバージョンでも動作が安定するよう調整しておりますので、ビーコンに関連した動作テストも緩和されます。
  
### マニュアル
  
[LocoSDK iOS Manual](https://github.com/beacrewjp/loco-sdk-ios-distribution/wiki)  
  
### License
  
© Beacrew Inc.  
  