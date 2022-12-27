#编译测试用例为可执行文件
add_executable(cpp_test test.cpp)
#把待测试的库连接到测试用例上
target_link_libraries(cpp_test evolution)

#告知cmake增加了测试,名为test_evolution,执行cpp_test这个可执行文件
add_test(
  NAME
    test_evolution
  COMMAND
    $<TARGET_FILE:cpp_test>
  )
