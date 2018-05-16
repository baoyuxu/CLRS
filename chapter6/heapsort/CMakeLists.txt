project(heapsort)

file(RELATIVE_PATH rel ${CMAKE_BINARY_DIR} ${PROJECT_BINARY_DIR})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/out/${rel}/bin )

add_executable(heapsort heapsort.cpp)
