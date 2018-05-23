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

#include "tsabohy/hidden_word.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void CreateHiddenWord(HiddenWord *hidden_word, const char *word) {
  size_t word_length = strlen(word);
  hidden_word->word = malloc(sizeof(char) * (word_length + 1));
  hidden_word->founds = malloc(sizeof(bool) * strlen(word));
  snprintf(hidden_word->word, word_length + 1, "%s", word);
  for (size_t i = 0; i < word_length; i++) {
    hidden_word->founds[i] = false;
  }
  hidden_word->length = word_length;
}

void FreeHiddenWord(HiddenWord *hidden_word) {
  free(hidden_word->word);
  free(hidden_word->founds);
}
