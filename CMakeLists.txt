cmake_minimum_required (VERSION 2.8)
project (Tsabohy)

option (BUILD_TESTS "Build tests." ON)

if (BUILD_TESTS)
  find_package (cmocka)

  macro (add_test name)
    add_executable (test-basic ${name})
    target_link_libraries (test-basic cmocka)
  endmacro (add_test)

  add_test (tests/basic.c)

endif (BUILD_TESTS)
