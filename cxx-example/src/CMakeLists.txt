#将main.cpp编译成可执行文件
add_executable(automata main.cpp)

#进入各个内部库到可执行目录
add_subdirectory(evolution)
add_subdirectory(initial)
add_subdirectory(io)
add_subdirectory(parser)

target_link_libraries(automata
  PRIVATE
    conversion  #外部库
    evolution   #内部库
    initial     #内部库
    io          #内部库
    parser      #内部库
  )
