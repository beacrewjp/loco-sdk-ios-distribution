Pod::Spec.new do |s|
  s.name = 'BeacrewLoco'
  s.version = '2.9.0'
  s.license = { :type => 'Copyright', :text => 'Copyright 2017 Beacrew Inc.' }
  s.summary = 'BeacrewLoco SDK for iOS'
  s.homepage = 'http://beacrew.jp'
  s.author = 'Beacrew Inc.'
  s.module_name = 'BeacrewLoco'
  s.ios.deployment_target = '15.0'
  s.ios.frameworks = 'UIKit', 'Foundation', 'SystemConfiguration', 'CoreLocation', 'CoreBluetooth'
  s.source = { :http => 'https://github.com/beacrewjp/loco-sdk-ios-distribution/releases/download/v#{s.version}/BeacrewLocoDynamic.xcframework.zip' }
  s.ios.vendored_frameworks = 'BeacrewLoco.xcframework'
end
