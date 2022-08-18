#include <stdio.h>
#include <string.h>

#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>

#include "../Arp-Language/Arp-Language.h"
#include "TokenRegex.h"

void ArpInt_initialize()
{
    ArpInt_initialize_token_regex_library();
}

int ArpInt_interpret_code(const char* code, uint64_t length)
{
    // TODO: Consider naming this function "tokenize" or make a tokenizer module within the library

    pcre2_code_8* re = ArpInt_compile_pcre2_regex_for_token_matching("[a-zA-z]", 8);

    for (uint64_t i = 0; i < length; i++)
    {
        char currentChar = code[i];
        int result = ArpInt_match_pcre2_regex_single_char(re, currentChar);
        switch (result)
        {
        case 1:
            printf("%c", currentChar);
            break;
        case -1:
            break;
        default:
            break;
        }
    }

    return 1;
}

int main(int argCount, char* argValues)
{
    ArpInt_initialize();

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

    ArpInt_interpret_code(rawText, size);

	return 0;
}