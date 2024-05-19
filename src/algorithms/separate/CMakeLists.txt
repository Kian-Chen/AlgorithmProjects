add_library(separate STATIC
    DPSolution.cpp
    BruteForceSolution.cpp
)

target_include_directories(separate PUBLIC
    ${CMAKE_SOURCE_DIR}/src/include
)
