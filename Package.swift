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
            checksum: "ead44433b3e76601c92d0b61461d89f3d53b507eab01046a47f1a8d10f6e069d"
        ),
        .binaryTarget(
            name: "BeacrewLocoStaticBinary",
            url: "https://github.com/beacrewjp/loco-sdk-ios-distribution/releases/download/v2.9.0/BeacrewLocoStatic.xcframework.zip",
            checksum: "3c8372c63ba04752790a99c17470759521b6ff63a9bc714fb821470e4092a789"
        ),
        .target(
            name: "BeacrewLocoDynamicWrapper",
            dependencies: [
                .target(name: "BeacrewLocoDynamicBinary"),
                .product(name: "Realm", package: "realm-swift")
            ],
            path: "Sources/BeacrewLocoWrapper"
        ),
        .target(
            name: "BeacrewLocoStaticWrapper",
            dependencies: [
                .target(name: "BeacrewLocoStaticBinary"),
                .product(name: "Realm", package: "realm-swift")
            ],
            path: "Sources/BeacrewLocoWrapper"
        )
    ]
)