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
// DEALINGS IN THE SOFTWARE.

#ifndef INCLUDE_TSABOHY_HIDDEN_WORD_H_
#define INCLUDE_TSABOHY_HIDDEN_WORD_H_

#include <stdbool.h>
#include <stddef.h>

typedef struct HiddenWord HiddenWord;

// Structure used to hold hidden word and his length and founds characters.
struct HiddenWord {
  const char *word;
  bool *founds;
  size_t length;
};

// Create an hidden word.
// If CreateHiddenWord was called you must call FreeHiddenWord to free memory
// previously allocated.
HiddenWord* NewHiddenWord(const char *word);

// Free memory allocated by create_hidden_word.
void DestroyHiddenWord(HiddenWord *hidden_word);

// Check if a character is in the hidden word and change the corresponding
// founds to true.
bool InHiddenWord(HiddenWord *hidden_word, const char c);

#endif  // INCLUDE_TSABOHY_HIDDEN_WORD_H_
