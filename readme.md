SOMEIP_DEMO

本demo来自他人，博客地址：

[SOMEIP环境搭建以及Demo详细介绍](https://blog.csdn.net/qq_30391343/article/details/123568915)

需要编译的其他依赖库可以参考如下：

```
https://github.com/blackbattery/commonapi_someip_demo.git
```

经过ubuntu 20.04测试通过

```
git clone https://github.com/blackbattery/SOMEIP-Demo.git
cd build 
sudo cmake ..
#如果遇到权限问题，请自行处理 
sudo make 
```

运行：

源码已经经过编译，可以直接到install目录执行脚本

service

```
cd install
./runAcefService.sh
```

client 

```
cd install
./runAcefClient.sh
```

如果重新生成文件，可以执行如下脚本

`./generate.sh`
