#ifndef BARCODEDECODER_H
#define BARCODEDECODER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "Defines.h"
#include "MatrixOps.h"

/**
 * @brief Inital barcode decoder. Returns the decoded barcode string
 * 
 * @param signalBC The raw read barcode from the standart input
 * @return char*
 */
char* signalDecoder(char* signalBC);

/**
 * @brief Decodes an already translated from light signals barcode string 
          into product barcode numbers.
 * 
 * @param code An already translated barcode string
 * @return int* 
 */
int* decodeNumbers(char* code);

/**
 * @brief Prints the final decoded into product numbers barcode
 */
void printBarCode(int* decoded, int size);

#endif /* BARCODEDECODER_H */