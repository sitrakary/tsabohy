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
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include <cmocka.h>

#include "tsabohy/hidden_word.h"

static int SetUp(void **state) {
  HiddenWord* hidden_word = NULL;
  hidden_word = NewHiddenWord("abc");
  *state = hidden_word;
  return 0;
}

static int TearDown(void **state) {
  HiddenWord *hidden_word = *state;
  DestroyHiddenWord(hidden_word);
  return 0;
}

static void NewHiddenWordTest(void **state) {
  HiddenWord *hidden_word = *state;
  assert_string_equal(hidden_word->word, "abc");
  assert_int_equal(hidden_word->length, 3);
}

static void AllCharactersAreHiddenAtCreateTimeTest(void **state) {
  HiddenWord *hidden_word = *state;
  for (size_t i = 0; i < hidden_word->length; i++) {
    assert_false(hidden_word->founds[i]);
  }
}

static void InHiddenWordTest(void **state) {
  HiddenWord *hidden_word = *state;
  assert_true(InHiddenWord(hidden_word, 'a'));
  assert_false(InHiddenWord(hidden_word, 'z'));
}

int main(int argc, char **argv) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_setup_teardown(NewHiddenWordTest, SetUp, TearDown),
    cmocka_unit_test_setup_teardown(AllCharactersAreHiddenAtCreateTimeTest, SetUp, TearDown),
    cmocka_unit_test_setup_teardown(InHiddenWordTest, SetUp, TearDown)
  };
  return cmocka_run_group_tests(tests, SetUp, TearDown);
}
