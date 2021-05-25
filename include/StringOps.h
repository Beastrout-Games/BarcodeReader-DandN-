#ifndef STRINGOPS_H
#define STRINGOPS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Defines.h"

void sliceString(char* code, char** slicedCode, int size);
char* reverseStr(char* string);

#endif /* STRINGOPS_H */