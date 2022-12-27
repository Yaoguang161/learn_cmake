#编译动态库,暂不添加任何源码
add_library(conversion "")

#随后用target_sources添加源码
#这种方式更好,因为可以更细粒度地访问权限.
#例如对cpp文件就是PRIVATE,而hpp则是PUBLIC
target_sources(conversion
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/conversion.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/conversion.hpp
  )

#增加头文件目录
target_include_directories(conversion
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )
