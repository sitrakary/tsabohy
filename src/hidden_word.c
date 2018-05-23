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

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool InHiddenWord(HiddenWord *hidden_word, const char c) {
  bool founds = false;
  for (size_t i = 0; i < hidden_word->length; i++) {
    if (hidden_word->word[i] == c) {
      founds = true;
      hidden_word->founds[i] = true;
    }
  }
  return founds;
}

HiddenWord* NewHiddenWord(const char *word) {
  HiddenWord *hidden_word = malloc(sizeof(HiddenWord));
  bool *founds = malloc(sizeof(bool) * strlen(word));
  for (size_t i = 0; i < strlen(word); i++) {
    founds[i] = false;
  }
  hidden_word->word = word;
  hidden_word->founds = founds;
  hidden_word->length = strlen(word);
  return hidden_word;
}

void DestroyHiddenWord(HiddenWord *hidden_word) {
  free(hidden_word->founds);
  free(hidden_word);
}
