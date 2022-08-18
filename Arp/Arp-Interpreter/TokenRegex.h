#pragma once

#define bTrue 1
#define bFalse 0

#include <stdint.h>

typedef uint8_t bool_t;

bool_t ArpInt_initialize_token_regex_library();

bool_t ArpInt_is_letter(char character);
bool_t ArpInt_is_number(char character);