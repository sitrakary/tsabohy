cmake_minimum_required (VERSION 2.8)
project (Tsabohy)

include_directories ("${CMAKE_SOURCE_DIR}/include")

add_library (tsabohy src/hidden_word.c)

option (BUILD_TESTS "Build tests." ON)

if (BUILD_TESTS)
  find_package (cmocka)

  macro (add_test name)
    add_executable (${name} tests/${name}.c)
    target_link_libraries (${name} tsabohy cmocka)
  endmacro (add_test)

  add_test (basic)
  add_test (hidden_word_test)
endif (BUILD_TESTS)
