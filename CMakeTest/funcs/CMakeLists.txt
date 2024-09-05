#递归将本文件夹下所有cpp放到FUNCS变量中
file(GLOB_RECURSE FUNCS ./ *.cpp)
#将FUNCS所有cpp编译为funcs这个lib库
add_library(funcs ${FUNCS})