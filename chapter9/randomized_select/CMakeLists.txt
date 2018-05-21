project(randomized_select)
file(RELATIVE_PATH rel ${CMAKE_BINARY_DIR} ${PROJECT_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/out/${rel}/bin )
aux_source_directory(./src SRC)

include_directories(./header)
add_executable(randomized_select_test ${SRC} ./test/randomized_select_test.cpp)
target_link_libraries(randomized_select_test gtest gtest_main gmock pthread)
