#ifndef BARCODE_VALIDATION_H
#define BARCODE_VALIDATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*Error codes*/
#define VALID_CODE 1
#define CHECKSUM_ERR 2
#define LEFT_SIDE_ERR 3
#define RIGHT_SIZE_ERR 4

/**
 * @brief Makes all the validations to determine if the barcode is valid
 * and returns the error code
 * 
 * @param decoded Pointer to a fully decoded barcode number, with  readable         C and K checksum values
 * @param size Size/Length of the barcode number
 * @return int 
 */
int isValidCode(int* decoded, int size);

/**
 * @brief Handles the different types of errors
 * 
 * @param errnum - The status number of the error
 */
void printErrorStatus(int errnum);

#endif /* BARCODE_VALIDATION_H */