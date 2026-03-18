Pod::Spec.new do |s|
  s.name = 'BeacrewLoco'
  s.version = '2.8.1'
  s.license = 'private'
  s.summary = 'BeacrewLoco SDK for iOS'
  s.homepage = 'http://beacrew.jp'
  s.author = 'Beacrew Inc.'
  s.module_name = 'BeacrewLoco'
  s.ios.deployment_target = '15.0'
  s.ios.frameworks = 'UIKit', 'Foundation', 'SystemConfiguration', 'CoreLocation', 'CoreBluetooth'
  s.source = { :path => '*.*' }
  s.ios.vendored_frameworks = 'BeacrewLoco.xcframework'
end
