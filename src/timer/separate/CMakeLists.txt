add_executable(separate_generate_data generate_data.cpp)
target_link_libraries(separate_generate_data separate TimerLib)
target_include_directories(separate_generate_data PUBLIC
    ${CMAKE_SOURCE_DIR}/src/include
)

add_executable(separate_time_algorithms time_algorithms.cpp)
target_link_libraries(separate_time_algorithms separate TimerLib)
target_include_directories(separate_time_algorithms PUBLIC
    ${CMAKE_SOURCE_DIR}/src/include
)
