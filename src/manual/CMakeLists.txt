add_executable(manual_k-th_heap k-th_heap.cpp)
target_link_libraries(manual_k-th_heap k-th)
target_include_directories(manual_k-th_heap PUBLIC
    ${CMAKE_SOURCE_DIR}/src/include
)

add_executable(manual_k-th_random k-th_random.cpp)
target_link_libraries(manual_k-th_random k-th)
target_include_directories(manual_k-th_random PUBLIC
    ${CMAKE_SOURCE_DIR}/src/include
)

add_executable(manual_k-th_median k-th_median.cpp)
target_link_libraries(manual_k-th_median k-th)
target_include_directories(manual_k-th_median PUBLIC
    ${CMAKE_SOURCE_DIR}/src/include
)

add_executable(manual_separate_dp separate_dp.cpp)
target_link_libraries(manual_separate_dp separate)
target_include_directories(manual_separate_dp PUBLIC
    ${CMAKE_SOURCE_DIR}/src/include
)

add_executable(manual_separate_bruteforce separate_bruteforce.cpp)
target_link_libraries(manual_separate_bruteforce separate)
target_include_directories(manual_separate_bruteforce PUBLIC
    ${CMAKE_SOURCE_DIR}/src/include
)
