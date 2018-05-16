project(quick_sort)
file(RELATIVE_PATH rel ${CMAKE_BINARY_DIR} ${PROJECT_BINARY_DIR})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/out/${rel}/bin )
add_executable(quick_sort quick_sort.cpp)
add_executable(quick_sort_having_same_elem quick_sort_having_same_elem.cpp)
add_executable(randomized_quick_sort randomized_quick_sort.cpp)
