#include <stdio.h>

#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>

#include "../Arp-Language/Arp-Language.h"
#include "TokenRegex.h"

int ArpInterpreter_interpretCode(const char* code, uint64_t length)
{
    // TODO: Consider naming this function "tokenize" or make a tokenizer module within the library

    PCRE2_SPTR8 regex = ARPLANG_TOKENREGEX_INT;
    int errorCode;
    PCRE2_SIZE errOffset;
    //pcre2_compile_context* context;
    pcre2_code* re = pcre2_compile_8(regex, strlen(regex), 0, &errorCode, &errOffset, NULL);

    for (uint64_t i = 0; i < length; i++)
    {
        char currentChar = code[i];
        printf("%c", currentChar);
    }

    return 0;
}

int main(int argCount, char* argValues)
{
    FILE* codeFile = 0;
    char* rawText;
    long size;

    fopen_s(&codeFile, "../test/functions.arp", "r");
    if (codeFile == NULL)
        return 1;

    fseek(codeFile, 0L, SEEK_END);
    size = ftell(codeFile);
    fseek(codeFile, 0L, SEEK_SET);

    rawText = (char*)calloc(size, sizeof(char));
    if (rawText == NULL)
        return 2;

    fread(rawText, sizeof(char), size, codeFile);
    fclose(codeFile);

    ArpInterpreter_interpretCode(rawText, size);

	return 0;
}