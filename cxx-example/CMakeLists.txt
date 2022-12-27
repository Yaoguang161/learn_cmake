#cmake最低版本
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
#本项目名
project(recipe-07 LANGUAGES CXX)
#设置C++17标准,需要满足标准,不用C++扩展语法
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(GNUInstallDirs)
#静态库输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
#动态库输出目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
#可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# defines targets and sources
#进入src文件夹下面的CMakeLists.txt
add_subdirectory(src)

# contains an "external" library we will link to
#进入external文件夹下面的CMakeLists.txt
add_subdirectory(external)

# enable testing and define tests
#开启测试
enable_testing()
#进入test文件下面的CMakeLists.txt
add_subdirectory(tests)
