cmake_minimum_required(VERSION 2.8)
project(Tsabohy)

set(TSABOHY_MAX_WORD_LENGTH 100)

configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_SOURCE_DIR}/include/tsabohy/config.h"
)

include_directories("${CMAKE_SOURCE_DIR}/include")

add_library(tsabohy src/hidden_word.c)

option(BUILD_TESTS "Build tests." ON)

if(BUILD_TESTS)
  find_package (cmocka)
  add_executable(hidden_word_test tests/hidden_word_test.c)
  target_link_libraries(hidden_word_test tsabohy cmocka)
endif(BUILD_TESTS)
