#ifndef TEST_STRFUNCS_H
#define TEST_STRFUNCS_H

#include <stdio.h>

void strrev(char *s);

char* readline(char* invite, char *input_format, int (*check)(char* s), FILE* stream);

int check_word(char *s);

#endif //TEST_STRFUNCS_H
