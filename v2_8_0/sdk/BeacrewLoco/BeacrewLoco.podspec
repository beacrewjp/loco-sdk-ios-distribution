Pod::Spec.new do |s|
  s.name = 'BeacrewLoco'
  s.version = '2.8.0'
  s.license = 'private'
  s.summary = 'BeacrewLoco SDK for iOS'
  s.homepage = 'http://beacrew.jp'
  s.author = 'Beacrew Inc.'
  s.module_name = 'BeacrewLoco'
  s.ios.deployment_target = '12.0'
  s.ios.frameworks = 'UIKit', 'Foundation', 'SystemConfiguration', 'CoreLocation', 'CoreBluetooth'
  s.source = { :path => '*.*' }
  s.ios.vendored_frameworks = 'BeacrewLoco.xcframework'
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.requires_arc  = true
end
