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
            checksum: "2baf7664a1fc48aab8417f1c1b917fa41e518330313ada216de00adbcec7e500"
        ),
        .binaryTarget(
            name: "BeacrewLocoStaticBinary",
            url: "https://github.com/beacrewjp/loco-sdk-ios-distribution/releases/download/v2.9.0/BeacrewLocoStatic.xcframework.zip",
            checksum: "3ee686e8a9c5e5b0aff02a44f692ac2da99cf8731cde73e399e9e416df4aeb81"
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