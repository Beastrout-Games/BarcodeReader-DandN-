#include <stdio.h>
#include <stdlib.h>
#include "matrixOps.h"

void* matrixInit(int rows, int cols) {
    void **baseMatrix = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        baseMatrix[i] = calloc(cols, sizeof(int *));
    }
    return baseMatrix;
}

void matrixDelete(void **baseMatrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(baseMatrix[i]);
    }
    free(baseMatrix);
}

void matrixReset(int **baseMatrix, int rows, int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            baseMatrix[i][j] = 0;
        }
    }
}