# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.24
cmake_policy(SET CMP0009 NEW)

# srcs at biology/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "C:/Users/Asaki/Desktop/CMake/biology/include/*.h")
set(OLD_GLOB
  "C:/Users/Asaki/Desktop/CMake/biology/include/biology/Animal.h"
  "C:/Users/Asaki/Desktop/CMake/biology/include/biology/Carer.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/Users/Asaki/Desktop/CMake/build/CMakeFiles/cmake.verify_globs")
endif()

# srcs at biology/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "C:/Users/Asaki/Desktop/CMake/biology/src/*.cpp")
set(OLD_GLOB
  "C:/Users/Asaki/Desktop/CMake/biology/src/Animal.cpp"
  "C:/Users/Asaki/Desktop/CMake/biology/src/Carer.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/Users/Asaki/Desktop/CMake/build/CMakeFiles/cmake.verify_globs")
endif()

# srcs at pybmain/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "C:/Users/Asaki/Desktop/CMake/pybmain/include/*.h")
set(OLD_GLOB
  "C:/Users/Asaki/Desktop/CMake/pybmain/include/pybmain/myutils.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/Users/Asaki/Desktop/CMake/build/CMakeFiles/cmake.verify_globs")
endif()

# srcs at pybmain/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "C:/Users/Asaki/Desktop/CMake/pybmain/src/*.cpp")
set(OLD_GLOB
  "C:/Users/Asaki/Desktop/CMake/pybmain/src/main.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "C:/Users/Asaki/Desktop/CMake/build/CMakeFiles/cmake.verify_globs")
endif()
