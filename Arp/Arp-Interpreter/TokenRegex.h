#pragma once

#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>

typedef enum {
	ARPINT_TOKEN_EXPECT_MODE_BLOCK,
	ARPINT_TOKEN_EXPECT_MODE_WORD,
	ARPINT_TOKEN_EXPECT_MODE_STR_LITERAL,
} ArpInt_TokenExpectMode;

extern const char* ARPINT_TOKEN_RCURL;
extern const char* ARPINT_TOKEN_LCURL;
extern const char* ARPINT_TOKEN_MULT;
extern const char* ARPINT_TOKEN_DIV;
extern const char* ARPINT_TOKEN_ADD;
extern const char* ARPINT_TOKEN_SUB;
extern const char* ARPINT_TOKEN_INCR;
extern const char* ARPINT_TOKEN_DECR;
extern const char* ARPINT_TOKEN_AND;
extern const char* ARPINT_TOKEN_OR;

int ArpInt_initialize_token_regex_library();

pcre2_code_8* ArpInt_compile_pcre2_regex_for_token_matching(const char* regex_pattern, uint8_t length);
int ArpInt_match_pcre2_regex_single_char(pcre2_code_8* regex, char character);