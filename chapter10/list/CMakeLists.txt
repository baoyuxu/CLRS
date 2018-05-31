project(list)

set(PROJ_NAME list)
set(PROJ_TEST_NAME list_test)


file(RELATIVE_PATH rel ${CMAKE_BINARY_DIR} ${PROJECT_BINARY_DIR})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/out/${rel}/bin )

include_directories(./header)

aux_source_directory(./src SRC)

add_executable(${PROJ_TEST_NAME} ${SRC} ./test/${PROJ_TEST_NAME}.cpp)
target_link_libraries(${PROJ_TEST_NAME} gtest gtest_main gmock pthread)
