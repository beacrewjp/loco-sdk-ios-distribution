// swift-tools-version: 5.9
import PackageDescription

let package = Package(
    name: "BeacrewLoco",
    platforms: [
        .iOS(.v15)
    ],
    products: [
        .library(
            name: "BeacrewLoco",
            targets: ["BeacrewLocoWrapper"]) 
    ],
    dependencies: [
        .package(url: "https://github.com/realm/realm-swift.git", "10.46.0"..<"21.0.0")
    ],
    targets: [
        .binaryTarget(
            name: "BeacrewLocoBinary",
            url: "https://github.com/beacrewjp/loco-sdk-ios-distribution/releases/download/v2.8.2/BeacrewLoco.xcframework.zip",
            checksum: "8abbc76d173dadd576687edd79d8cd259d07ca10ebef827310798e5a1e73f978"
        ),
        .target(
            name: "BeacrewLocoWrapper",
            dependencies: [
                .target(name: "BeacrewLocoBinary"),
                .product(name: "Realm", package: "realm-swift")
            ],
            path: "Sources/BeacrewLocoWrapper"
        )
    ]
)