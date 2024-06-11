# 常用指令

## project 关键字

指定工程名和支持的语言



```CMake
# 指定工程名字，并支持所有语言（建议使用）
project(hello)
# 指定工程名字，并支持 C++ 语言
project(hello CXX)
# 指定工程名字，并支持 C/C++ 语言
project(hello C CXX)
```

## cmake_minimum_required 关键字

设置CMake最低版本

## set 关键字

用于显示指定变量，类似于变量赋值.  多个文件使用空格分开

```CMake
set(src_list main.cc)
set(src_list main.cc util.cc test.cc)
```

设置C++ 支持的版本

```CMake
set(CMAKE_CXX_STANDARD 11)		# C++11
set(CMAKE_CXX_STANDARD 14)		# C++14
```

## message 关键字

向终端用户输出自定义信息，主要包含 3 种信息：

- `SEND_ERROR` 生产错误，生成过程被跳过；
- `STATUS` 输出前缀为 – 的信息；
- `FATAL_ERROR` 立即终止所有 cmake 过程。

```cmake
message(STATUS "binary dir ${hello_BINARY_DIR}")
message(STATUS "source dir ${hello_SOURCE_DIR}")

# 输出内容，会有 -- 前缀
-- binary dir /home/mayw/tmp/cmake_test
-- source dir /home/mayw/tmp/cmake_test
```

## [aux_source_directory](https://so.csdn.net/so/search?q=aux_source_directory&spm=1001.2101.3001.7020) 关键字

查找目录中的所有源文件，并赋值给指定变量

```cmake
# 查找当前目录下的所有源文件，将名称保存到 src_list 变量中，可以使用 ${src_list} 进行引用
aux_source_directory(. src_list)
```



## include_directories 关键字

添加头文件目录，相当于 gcc/g++ 命令的 -I 参数的功能，如

```cmake
# 类似 gcc/g++ 中的 -I 选项
include_directories(../include)
```

## include 关键字

包含其他的 cmake 文件，被包含的文件一般以 cmake结尾，如
`include(../cmake/common.cmake)`

## add_definitions 关键字

添加定义信息，类似于 gcc/g++ 中的 CFLAGS 和 宏定义，如

```cmake
add_definitions(-g -Wall -O3)

# -D开表示宏定义
if(MSVC) 
	add_definitions(-D_WIN32_WINNT=0x600) 
endif()
```

## link_directories 关键字

添加库文件目录，相当于 gcc/g++ 命令的 -L 参数的功能，如

```cmake
# 类似 gcc/g++ 中的 -L 选项
link_directories(../lib ../lib64)
```

一般都是与 `add_executable` 配合使用，紧跟其后。

## add_executable 关键字

指定生成的可执行文件

```CMake
set(src_list main.cc)
add_executable(hello ${src_list})
# 生成可执行文件 hello，源文件读取变量 src_list 里的内容，也就是 main.cc,等价add_executable(hello main.cc)
# 若要链接 libmylib.so，可以添加
target_link_libraries(hello mylib)
```

**注意：工程名 hello 和生成的可执行文件 hello 没有任何关系，可以相同，也可以不相同。**

工程名是: project 

可执行文件: add_executable

## add_library 关键字

与`add_executable`类似，指定生成的库文件

```CMake
set(lib_src add.cpp)
add_library(add STATIC ${lib_src})
```

- add ：库文件名称，Linux 上生成库文件会自动加上前后缀，如当前的静态库文件名称为 libadd.a；
- STATIC ：静态库，动态库为 SHARED；
- ${lib_src} ：构造库文件所需的源码文件。

## add_subdirectory 关键字

`add_subdirectory (source_dir [binary_dir] [EXCLUDE_FROM_ALL])`
添加一个子目录并构建该子目录。

## CMake 语法的基本原则

- 变量使用 `${}` 方式取值，但是在 `if` 控制语句中是直接使用变量名；
- 指令参数使用括号，参数之间使用空格或分号分开，如 `add_executable(hello main.cc util.cc)`