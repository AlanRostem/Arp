#include "TokenRegex.h"
#include "pch.h"

static pcre2_match_data_8* matchData;

int ArpInt_initialize_token_regex_library()
{
    matchData = pcre2_match_data_create_8(1, NULL);
    return 1;
}

pcre2_code_8* ArpInt_compile_pcre2_regex_for_token_matching(const char* regex_pattern, uint8_t length)
{
    int errorCode;
    PCRE2_SIZE errOffset;
    pcre2_compile_context_8* context = pcre2_compile_context_create_8(NULL);
    pcre2_code_8* re = pcre2_compile_8(regex_pattern, length, 0, &errorCode, &errOffset, context);

    if (errorCode != 100)
    {
        char errMessage[200];
        pcre2_get_error_message_8(errorCode, errMessage, 200);
        printf("ErrorCode in compile %i: %s", errorCode, errMessage);
        return NULL;
    }

    return re;
}

int ArpInt_match_pcre2_regex_single_char(pcre2_code_8* regex, char character)
{
    int err = pcre2_match(regex, &character, 1, 0, PCRE2_ANCHORED, matchData, NULL);
    return err;
}
