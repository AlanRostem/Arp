//
// Created by Personal on 15/08/2022.
//

#include "Library.h"
#include "pcre2.h"

int ArpInterpreter_interpretCode(const char *code, uint64_t length)
{
    // TODO: Consider naming this function "tokenize" or make a tokenizer module within the library

    for (uint64_t i = 0; i < length; i++)
    {
        char currentChar = code[i];

        // int x = pcre2_regcomp(0, 0, 0);

    }

    return 0;
}
