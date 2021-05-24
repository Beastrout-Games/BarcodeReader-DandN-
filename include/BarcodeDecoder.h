#ifndef BARCODEDECODER_H
#define BARCODEDECODER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "Defines.h"
#include "MatrixOps.h"

void sliceString(char* code, char** slicedCode, int size);
int* decodeNumbers(char* code);
char* reverseStr(char* string);


#endif /* BARCODEDECODER_H */