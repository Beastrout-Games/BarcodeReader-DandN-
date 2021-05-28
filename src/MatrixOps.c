#include <stdio.h>
#include <stdlib.h>
#include "MatrixOps.h"
#include "Defines.h"

void* matrixInit(int rows, int cols) {
    void **baseMatrix = calloc(rows, sizeof(int *));
    CHECK_ALLOCATION_ERR(baseMatrix);

    for (int i = 0; i < rows; i++) {
        baseMatrix[i] = calloc(cols, sizeof(int *));
        CHECK_ALLOCATION_ERR(baseMatrix[i]);

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