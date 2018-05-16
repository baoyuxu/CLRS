project(maximum_subarray)

file(RELATIVE_PATH rel ${CMAKE_BINARY_DIR} ${PROJECT_BINARY_DIR})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/out/${rel}/bin )

add_executable(divide_and_conquer divide_and_conquer.cpp)
add_executable(linear linear.cpp)
