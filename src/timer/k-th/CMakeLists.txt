add_executable(k-th_generate_data generate_data.cpp)
target_link_libraries(k-th_generate_data k-th TimerLib)
target_include_directories(k-th_generate_data PUBLIC
    ${CMAKE_SOURCE_DIR}/src/include
)

add_executable(k-th_time_algorithms time_algorithms.cpp)
target_link_libraries(k-th_time_algorithms k-th TimerLib)
target_include_directories(k-th_time_algorithms PUBLIC
    ${CMAKE_SOURCE_DIR}/src/include
)
