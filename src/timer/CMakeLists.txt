add_library(TimerLib Timer.cpp)

# 设置头文件目录
target_include_directories(TimerLib PUBLIC
    ${CMAKE_SOURCE_DIR}/src/include
)

add_subdirectory(k-th)
add_subdirectory(separate)
