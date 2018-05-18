project(maximum_subarray)

file(RELATIVE_PATH rel ${CMAKE_BINARY_DIR} ${PROJECT_BINARY_DIR})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/out/${rel}/bin )

include_directories($ENV{GTEST_INC})
include_directories(./header)
link_directories($ENV{GTEST_LIB})

aux_source_directory(./src SRC)

add_executable(divide_and_conquer_test ${SRC} ./test/divide_and_conquer_test.cpp)
target_link_libraries(divide_and_conquer_test gtest gtest_main gmock pthread)

add_executable(linear_test ${SRC} ./test/linear_test.cpp)
target_link_libraries(linear_test gtest gtest_main gmock pthread)
