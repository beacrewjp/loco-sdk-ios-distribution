Pod::Spec.new do |s|
  s.name = 'BeacrewLoco'
  s.version = '2.7.0'
  s.license = { :type => 'Copyright', :text => 'Copyright 2017 Beacrew Inc.' }
  s.summary = 'BeacrewLoco SDK for iOS'
  s.homepage = 'http://beacrew.jp'
  s.author = 'Beacrew Inc.'
  s.module_name = 'BeacrewLoco'
  s.ios.deployment_target = '12.0'
  s.ios.frameworks = 'UIKit', 'Foundation', 'SystemConfiguration', 'CoreLocation', 'CoreBluetooth'
  s.source = { :git => 'https://github.com/beacrewjp/loco-sdk-ios-distribution/' }
  s.ios.vendored_frameworks = 'v2_7_0/sdk/BeacrewLoco/BeacrewLoco.framework'
  s.requires_arc  = true
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end
