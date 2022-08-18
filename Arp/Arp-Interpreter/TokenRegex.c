#include "TokenRegex.h"

#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>

#include <stdio.h>
#include <string.h>

static pcre2_match_data_8* matchData;

static pcre2_code_8* ArpInt_LetterRegexPattern;
static pcre2_code_8* ArpInt_NumberRegexPattern;

pcre2_code_8* ArpInt_compile_pcre2_regex_for_token_matching(const char* regex_pattern);
int ArpInt_match_pcre2_regex_single_char(pcre2_code_8* regex, char character);

bool_t ArpInt_initialize_token_regex_library()
{

    ArpInt_LetterRegexPattern = ArpInt_compile_pcre2_regex_for_token_matching("[a-zA-z]");
    ArpInt_NumberRegexPattern = ArpInt_compile_pcre2_regex_for_token_matching("[0-9]");

    matchData = pcre2_match_data_create_8(1, NULL);
    return bTrue;
}

bool_t ArpInt_is_letter(char character)
{
    return ArpInt_match_pcre2_regex_single_char(ArpInt_LetterRegexPattern, character) == 1;
}

bool_t ArpInt_is_number(char character)
{
    return ArpInt_match_pcre2_regex_single_char(ArpInt_NumberRegexPattern, character) == 1;
}

pcre2_code_8* ArpInt_compile_pcre2_regex_for_token_matching(const char* regex_pattern)
{
    int errorCode;
    PCRE2_SIZE errOffset;
    pcre2_compile_context_8* context = pcre2_compile_context_create_8(NULL);
    pcre2_code_8* re = pcre2_compile_8(regex_pattern, strlen(regex_pattern), 0, &errorCode, &errOffset, context);

    if (errorCode != 100)
    {
        char errMessage[200];
        pcre2_get_error_message_8(errorCode, errMessage, 200);
        printf("ErrorCode %i at index %i in regex compilation: %s", errorCode, errOffset, errMessage);
        return NULL;
    }

    return re;
}

int ArpInt_match_pcre2_regex_single_char(pcre2_code_8* regex, char character)
{
    int err = pcre2_match(regex, &character, 1, 0, PCRE2_ANCHORED, matchData, NULL);
    return err;
}
