#ifndef BARCODEREADER_H
#define BARCODEREADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Defines.h"

/**
 * @brief Reads the light signal from the standart input and returns it in string format
 * 
 * @param sizeOfInput The size of the barcode
 * @return char* 
 */
char* signalReader(int sizeOfInput);

#endif /* BARCODEREADER_H */