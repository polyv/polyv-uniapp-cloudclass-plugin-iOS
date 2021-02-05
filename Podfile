# Uncomment the next line to define a global platform for your project
# platform :ios, '9.0'

target 'HBuilder' do
  # Uncomment the next line if you're using Swift or would like to use dynamic frameworks
  use_frameworks!

  #通过 pod 导入 Masonry 的库会导致运行时报错找不到 'mas_remakeConstraints' 方法，改为手动导入
  # pod 'Masonry', '~> 1.1.0'
  #Uni-app 的插件开发工程里已包含了 SDWebImage 的库 libSDWebImage.a，不需要 CocoaPod 再次导入
  # pod 'SDWebImage', '4.4.0'
  # 每次升级 demo 源码之后，需要运行 ./PLVCloudClassUniPlugin/PLVCloudClassUniPlugin/ 路径下的 replaceImport 脚本，把代码中这两个库的头文件导入从 #import <库名/头文件>，改为 #import “头文件”。

  # Pods for PolyvCloudClassDemo
  pod 'PolyvCloudClassSDK', '~> 0.16.1' # polyv 云课堂 SDK
end
