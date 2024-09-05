 #需求最低cmake程序版本
 cmake_minimum_required(VERSION 3.12)
 #本工程名字
 project(Graphic)
 #本工程支持的C++版本
 set(CMAKE_CXX_STANDARD 17)
 #将funcs文件夹纳入到编译系统
 add_subdirectory(funcs)
 #点代表当前文件夹 搜索当前文件夹所有的cpp,加入SRCS变量中
 #aux_source_directory(. SRCS)
 #本工程所有cpp文件编译链接,生成exe
 #add_executable(SoftRender ${SRCS})
 add_executable(SoftRender "main.cpp")
 add_executable(main2 "main2.cpp")
 #将funcs.lib链接入SoftRender
 target_link_libraries(SoftRender funcs)
 