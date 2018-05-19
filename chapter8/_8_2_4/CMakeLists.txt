project(_8_2_4)
file(RELATIVE_PATH rel ${CMAKE_BINARY_DIR} ${PROJECT_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/out/${rel}/bin )
aux_source_directory(./src SRC)

include_directories(./header)
add_executable(_8_2_4_test ${SRC} ./test/_8_2_4_test.cpp)
target_link_libraries(_8_2_4_test gtest gtest_main gmock pthread)
