add_library(k-th STATIC
    HeapSelect.cpp
    RandomizedSelect.cpp
    MedianOfMedians.cpp
)

target_include_directories(k-th PUBLIC
    ${CMAKE_SOURCE_DIR}/src/include
)
