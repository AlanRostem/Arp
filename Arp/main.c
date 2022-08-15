#include "Arp-interpreter/Library.h"
#include "Arp-language/TokenRegex.h"
#include <stdio.h>

int main() {
    printf("%i %c", ArpInterpreter_interpretCode("Hello"), '\n');
    printf("%s", ARPLANG_TOKENREGEX_INT);
    return 0;
}
