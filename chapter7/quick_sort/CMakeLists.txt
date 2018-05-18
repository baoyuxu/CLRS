project(quick_sort)
file(RELATIVE_PATH rel ${CMAKE_BINARY_DIR} ${PROJECT_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/out/${rel}/bin )

include_directories($ENV{GTEST_INC})
link_directories($ENV{GTEST_LIB})

aux_source_directory(./src SRC)
add_executable(quick_sort_test ${SRC} ./test/quick_sort_test.cpp)
add_executable(quick_sort_having_same_elem_test ${SRC} ./test/quick_sort_having_same_elem_test.cpp)
add_executable(randomized_quick_sort_test ${SRC} ./test/randomized_quick_sort_test.cpp)
target_link_libraries(quick_sort_test gtest gtest_main gmock pthread)
target_link_libraries(quick_sort_having_same_elem_test gtest gtest_main gmock pthread)
target_link_libraries(randomized_quick_sort_test gtest gtest_main gmock pthread)

