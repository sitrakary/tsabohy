// Copyright 2018 Sitraka Ratsimba
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom
// the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include <cmocka.h>

#include "tsabohy/hidden_word.h"

static int SetUp(void **state) {
  HiddenWord *hidden = NewHiddenWord("abc");
  *state = hidden;
  return 0;
}

static int TearDown(void **state) {
  DeleteHiddenWord(*state);
  return 0;
}

static void TestStructHiddenWord(void **state) {
  HiddenWord *hidden = *state;
  assert_int_equal(hidden->length, 3);
  assert_string_equal(hidden->word, "abc");
  for (size_t i = 0; i < hidden->length; i++) {
    assert_false(hidden->founds[i]);
  }
  assert_true(hidden->founds[hidden->length]);
}

static void TestIsInHiddenWord(void **state) {
  HiddenWord *hidden_word = *state;
  assert_false(InHiddenWord(hidden_word, 'z'));
  assert_true(InHiddenWord(hidden_word, 'a'));
}

static void TestInHiddenWordUpdatesFounds(void **state) {
  HiddenWord *hidden_word = *state;
  InHiddenWord(hidden_word, 'a');
  assert_true(hidden_word->founds[0]);
}

static void TestFoundsHiddenWord(void **state) {
  HiddenWord *hidden_word = *state;
  InHiddenWord(hidden_word, 'a');
  InHiddenWord(hidden_word, 'b');
  InHiddenWord(hidden_word, 'c');
  assert_true(FoundsHiddenWord(hidden_word));
}

int main(int argc, char **argv) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_setup_teardown(TestStructHiddenWord, SetUp, TearDown),
    cmocka_unit_test_setup_teardown(TestIsInHiddenWord, SetUp, TearDown),
    cmocka_unit_test_setup_teardown(TestInHiddenWordUpdatesFounds,
      SetUp, TearDown),
    cmocka_unit_test_setup_teardown(TestFoundsHiddenWord, SetUp, TearDown)
  };
  return cmocka_run_group_tests(tests, SetUp, TearDown);
}
