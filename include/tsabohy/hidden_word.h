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

#ifndef INCLUDE_TSABOHY_HIDDEN_WORD_H_
#define INCLUDE_TSABOHY_HIDDEN_WORD_H_

#include <stdbool.h>
#include <stddef.h>

#include "tsabohy/config.h"

typedef struct HiddenWord HiddenWord;

struct HiddenWord {
  size_t length;
  bool founds[TSABOHY_MAX_WORD_LENGTH];
  char word[TSABOHY_MAX_WORD_LENGTH];
};

HiddenWord* NewHiddenWord(const char *word);

void DeleteHiddenWord(HiddenWord *hidden_word);

bool InHiddenWord(HiddenWord *hidden_word, const char c);

#endif  // INCLUDE_TSABOHY_HIDDEN_WORD_H_
