#include <stdio.h>
#include <string.h>

#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>

#include "Arp-Language.h"
#include "TokenRegex.h"

typedef enum {
    ARPINT_TOKEN_EXPECT_MODE_ANYTHING,
    ARPINT_TOKEN_EXPECT_MODE_WORD,
    ARPINT_TOKEN_EXPECT_MODE_EXPRESSION,
    ARPINT_TOKEN_EXPECT_MODE_STR_LITERAL,
    ARPINT_TOKEN_EXPECT_MODE_NUMBER_LITERAL,
} ArpInt_TokenExpectMode;

typedef enum {
    ARPINT_EXPECTERRCODE_OK,
    ARPINT_EXPECTERRCODE_UNEXPECTED_TOKEN,
} ArpInt_ExpectErrorCode;

static ArpInt_TokenExpectMode current_expect_mode = ARPINT_TOKEN_EXPECT_MODE_WORD;

void ArpInt_initialize()
{
    ArpInt_initialize_token_regex_library();
}

void ArpInt_expect_word(char character)
{

}

int ArpInt_interpret_code(const char* code, uint64_t length)
{
    // TODO: Consider naming this function "tokenize" or make a tokenizer module within the library

    for (uint64_t i = 0; i < length; i++)
    {
        char current_char = code[i];
        switch (current_expect_mode) 
        {
        case ARPINT_TOKEN_EXPECT_MODE_WORD:
            ArpInt_expect_word(current_char);
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