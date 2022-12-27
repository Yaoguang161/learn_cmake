- [CMake教程](#cmake教程)
- [主要使用方式](#主要使用方式)
- [修改文件后使用方式](#修改文件后使用方式)
- [构建与安装方式](#构建与安装方式)
- [指令 -B --build](#指令--b---build)
  - [解释:](#解释)
- [-D选项: 指定配置变量(又称缓存变量)](#-d选项-指定配置变量又称缓存变量)
  - [补充:](#补充)
- [-G选项: 指定要用的生成器](#-g选项-指定要用的生成器)
- [1.添加源文件](#1添加源文件)
  - [1.1一个源文件](#11一个源文件)
  - [1.2多个源文件](#12多个源文件)
  - [1.3源码放在子文件夹里](#13源码放在子文件夹里)
- [2.项目配置变量](#2项目配置变量)



# CMake教程

# 主要使用方式
1. 在目录下同时用`CMakeLists.txt`文件和`main.cpp`文件,两个文件中的代码都是正确的
2. 执行在上面两文件的目录下执行`cmake -B build`
3. 接着执行 `cmake --build build`
4. 然后会在build下生成main可执行文件
5. 使用`build/main`即可运行程序

# 修改文件后使用方式
1. 读取当前目录的` CMakeLists.txt`，并在 `build `文件夹下生成`build/Makefile`：  
`cmake -B build`
2. 让 make 读取 build/Makefile，并开始构建 a.out：
   `make -C build`
    1. 以下命令和上一个等价，但更跨平台：`cmake --build build`
    2. 也可以`cd build && make`
3. 执行生成的 a.out：
`build/a.out`
4. 如果源文件修改了，直接进行第2步即可，不用`rm-rf build`.


# 构建与安装方式
1. `mkdir build` 需要先创建build目录
2. `cd build` 切换到build目录
3. `cmake .. `在build目录运行cmake<源码目录>生成Makefile
4. `make -j4` 执行本地的构建系统make真正开始构建(4进程并行)
5. `sudo make install` 让本地的构建系统执行安装步骤
6. `cd ..` 回到源码目录

# 指令 -B --build
* `cmake -B build `//在源码目录用-B之间创建build目录并生成build/Makefile
* `cmake --build build -j4` //自动调用本地的构建系统在build里构建,即 `make -C build -j4`
* `sudo cmake --build build --target install` //调用本地的构建系统执行install这个目标,即安装
## 解释:
* `cmake -B build` 免去了先创建build目录在切换进去再指定源码目录的麻烦
* `cmake --build build` 统一了不同平台(Linux上会调用make,Windows上调用devenv.exe)

结论: 所以从现在开始,如果在命令行中操作cmake,请使用更方便的-B和--build命令

# -D选项: 指定配置变量(又称缓存变量)
 `CMake`项目的构建分为两步:  
1. 第一步是`cmake -B build`,称为配置阶段(configure),只检测环境并生成构建规则,会在build目录下生成本地构建系统能识别的项目文件(Makefile或是.sln)
2. 第二步是`cmake --build build`,称为构建阶段(build),这时才实际调用编辑器来编译代码
## 补充:
* 在配置阶段可以通过-D 设置缓存变量,第二次配置时,之前的-D 添加仍然会被保留.

# -G选项: 指定要用的生成器
* linux系统上的CMake默认用是Unix Makefiles生成器;Windows系统默认是Visual Studio 2019生成器;MacOS系统默认的是Xcode生成器
* 可以用-G参数改用别的生成器.例如`cmake -GNinja`会生成Ninja这个构建系统的构建规则.Ninja是一个高性能,跨平台的构建系统,Linux,Windows,MacOS上都可以用.
* 代码: `cmake -GNinja -B build`
* 性能上: Ninja > Makefile > MSBuild
  

# 1.添加源文件
## 1.1一个源文件
源文件名称: main.cpp
1. CMake中添加一个可执行文件作为构建目标
`add_executable(main main.cpp)`
2. 另一种方式: 先创建目标,稍后在添加源文件
```cmake
add_executable(main)
target_sources(main PUBLIC main.cpp)
```
## 1.2多个源文件
```cmake
add_executable(main)
target_sources(main PULBIC main.cpp other.cpp)


#或者使用变量存储
add_executable(main)
set(source main.cpp other.cpp other.h)
target_source(main PUBLIC ${source})
```

* 使用GLOB自动查找当前目录下指定扩展名的文件,实现批量添加源文件

```cmake
add_executable(main)
file(GLOB sources *.cpp *.h)
target_sources(main PUBLIC ${sources})
```
*  启用CONFIGURE_DEPENDS选项,当添加新文件时,自动更新变量
```cmake
add_executable(main)
file(GLOB sources CONFIGURE_DEPENDS *.cpp *.h)
target_sources(main PUBLIC ${sources})
```

## 1.3源码放在子文件夹里
* 使用aux_source_directrory,自动搜集需要的文件后缀名
```cmake
add_executable(main)
aux_source_directory(. sources)
aux_source_directory(mylib sources)
target_sources(main PUBLIC ${sources})
```
* GLOB_RECURSE能自动包含所有子文件下的文件,但是会把build目录里生成的临时.cpp文件也加进来
```cmake
add_executable(main)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS *.cpp *.h)
target_sources(main PUBLIC ${sources})
```
# 2.项目配置变量
* CMAKE_BUILD_TYPE(特殊变量)控制构建的类型,选择调试模式还是发布模式.可选参数有:
  * Debug调试模式,完全不优化,生成调试信息,方便调试程序
  * Release发布模式,优化程度最高,性能最佳,但是编译比Debug慢
  * MinSizeRel最小体积发布,生成的文件比Release更小,不完全优化,减少二进制体积
  * RelWithDebInfo带调试信息发布,生成的文件比Release更大.
  * 默认情况下为Debug 
* 小技巧: 设定一个变量的默认值(在用户没有指定时为Release)
```cmake
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
```
