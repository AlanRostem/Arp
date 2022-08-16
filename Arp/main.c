#include "Arp-interpreter/Library.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* codeFile;
    char* rawText;
    long size;

    codeFile = fopen("test/functions.arp", "r");
    if (codeFile == NULL)
        return 1;

    fseek(codeFile, 0L, SEEK_END);
    size = ftell(codeFile);
    fseek(codeFile, 0L, SEEK_SET);

    rawText = (char*)calloc(size, sizeof(char));
    if(rawText == NULL)
        return 2;

    fread(rawText, sizeof(char), size, codeFile);
    fclose(codeFile);

    ArpInterpreter_interpretCode(rawText, size);

    return 0;
}
