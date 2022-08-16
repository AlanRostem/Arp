//
// Created by Personal on 15/08/2022.
//

#include "Library.h"
#include "Arp-language/TokenRegex.h"

#include <string.h>

#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>

int ArpInterpreter_interpretCode(const char *code, uint64_t length)
{
    // TODO: Consider naming this function "tokenize" or make a tokenizer module within the library

    PCRE2_SPTR8 regex = ARPLANG_TOKENREGEX_INT;
    int errorCode;
    PCRE2_SIZE errOffset;
    pcre2_compile_context* context;
    pcre2_code* re = pcre2_compile_8(regex, strlen(regex), 0, &errorCode, &errOffset, context);

    for (uint64_t i = 0; i < length; i++)
    {
        char currentChar = code[i];

    }

    return 0;
}
