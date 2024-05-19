cmake_minimum_required(VERSION 3.10)
project(Midterm)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(${CMAKE_SOURCE_DIR}/src/include)

# 包含子目录
add_subdirectory(src/algorithms/k-th)
add_subdirectory(src/algorithms/separate)
add_subdirectory(src/timer)
add_subdirectory(src/manual)
