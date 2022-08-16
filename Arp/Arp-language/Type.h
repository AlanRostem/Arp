//
// Created by arost on 8/15/2022.
//

#ifndef ARP_TYPE_H
#define ARP_TYPE_H

typedef enum {
    ARPLANG_TYPE_INT,
    ARPLANG_TYPE_FLOAT,
    ARPLANG_TYPE_STRING,
    ARPLANG_TYPE_DICT,
    ARPLANG_TYPE_ARRAY,
    ARPLANG_TYPE_FUNCTION,
} ArpLang_Type;

typedef enum {
    ARPLANG_TOKEN_BRACKET_OPEN,
    ARPLANG_TOKEN_BRACKET_CLOSE,
} ArpLang_Token;

#endif //ARP_TYPE_H
