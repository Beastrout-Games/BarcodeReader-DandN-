#ifndef MATRIXOPS_H
#define MATRIXOPS_H

/**
 * @brief Allocates memory and initialisez a matrix as an array of pointers.
 * 
 * @param rows The rows size of the matrix
 * @param cols The cols size of the matrix
 * @return void* - Returns a generic pointer to an allocated (empty) matrix. 
 *                 Cast as needed.
 */
void* matrixInit(int rows, int cols);

/**
 * @brief Deletes the matrix data and frees the allocated memory
 * 
 * @param baseMatrix Pointer to the matrix to be deleted
 * @param rows The number of rows of the matrix
 */
void matrixDelete(void **baseMatrix, int rows);

/**
 * @brief Resets the matrix to all zero values.
 * 
 * @param baseMatrix Pointer to the matrix to be reset
 * @param rows Number of rows of the matrix
 * @param cols Number of cols of the matrix
 */
void matrixReset(int **baseMatrix, int rows, int cols);

#endif /* MATRIXOPS_H */