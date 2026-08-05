// swift-tools-version: 5.9
import PackageDescription

let package = Package(
    name: "BeacrewLoco",
    platforms: [
        .iOS(.v15)
    ],
    products: [
        .library(name: "BeacrewLocoDynamic", targets: ["BeacrewLocoDynamicWrapper"]),
        .library(name: "BeacrewLocoStatic", targets: ["BeacrewLocoStaticWrapper"])
    ],
    dependencies: [
        .package(url: "https://github.com/realm/realm-swift.git", from: "20.0.4")
    ],
    targets: [
        .binaryTarget(
            name: "BeacrewLocoDynamicBinary",
            url: "https://github.com/beacrewjp/loco-sdk-ios-distribution/releases/download/v2.9.0/BeacrewLocoDynamic.xcframework.zip",
            checksum: "e39a3764bd19fee2b820a0561064711ad97a955b117e6504d28e1daf8e788ac8"
        ),
        .binaryTarget(
            name: "BeacrewLocoStaticBinary",
            url: "https://github.com/beacrewjp/loco-sdk-ios-distribution/releases/download/v2.9.0/BeacrewLocoStatic.xcframework.zip",
            checksum: "e78ba92908314c8ed80157a2b9e194ace74064017d7fafc3c34d29d970d65a3a"
        ),
        .target(
            name: "BeacrewLocoDynamicWrapper",
            dependencies: [
                .target(name: "BeacrewLocoDynamicBinary"),
                .product(name: "Realm", package: "realm-swift")
            ],
            path: "Sources/BeacrewLocoDynamicWrapper"
        ),
        .target(
            name: "BeacrewLocoStaticWrapper",
            dependencies: [
                .target(name: "BeacrewLocoStaticBinary"),
                .product(name: "Realm", package: "realm-swift")
            ],
            path: "Sources/BeacrewLocoStaticWrapper"
        )
    ]
)