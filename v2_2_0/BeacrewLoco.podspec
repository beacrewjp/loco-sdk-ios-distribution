Pod::Spec.new do |s|
  s.name = 'BeacrewLoco'
  s.version = '2.2.0'
  s.license = { :type => 'Copyright', :text => 'Copyright 2017 Beacrew Inc.' }
  s.summary = 'BeacrewLoco SDK for iOS'
  s.homepage = 'http://beacrew.jp'
  s.author = 'Beacrew Inc.'
  s.module_name = 'BeacrewLoco'
  s.ios.deployment_target = '9.0'
  s.ios.frameworks = 'UIKit', 'Foundation', 'SystemConfiguration', 'CoreLocation', 'CoreBluetooth'
  s.source = { :git => 'https://github.com/beacrewjp/loco-sdk-ios-distribution/' }
  s.ios.vendored_frameworks = 'v2_2_0/sdk/BeacrewLoco/BeacrewLoco.framework'
  s.requires_arc  = true
end
