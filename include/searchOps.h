#ifndef SEARCHOPS_H
#define SEARCHOPS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "defines.h"
#include "matrixOps.h"
#include "queueOps.h"
#include "fileParser.h"
#include "publicAPI.h"

/**
 * @brief Searches for the longest possible path in a given Matrix by
 *        using the Breadth First algorithm and a Queue.
 *
 * @param rows The rows size of the matrix
 * @param cols The cols size of the matrix
 * @return int
 */
int searchBFS(int rows, int cols);

/**
 * @brief Checks the neighboring cells in all four cardinal
 *        direcrtions of a given Matrix node. If a given neighbor
 *        contains the same value, it will enqueue it for later verification.
 *
 * @param x Row coordinate of the verified Node
 * @param y Col coordinate of the verified Node
 * @param rows The rows size of the matrix
 * @param cols The cols size of the matrix
 * @param keyValue The value of the verified Node
 */
void checkNeighbors(int x, int y, int rows, int cols, int keyValue);

/**
 * @brief Verifies if a given Node is within the boundaries of the matrix
 *        and if its value is same as a predefined one. Returns true or false
 *        based on the check.
 *
 * @param x Rows coordinate of the node to be verified
 * @param y Cols coordinate of the Node to be verified
 * @param rows The rows size of the matrix
 * @param cols The cols size of the matrix
 * @param keyValue The predefined value to be matched.
 * @return true
 * @return false
 */
bool isValid(int x, int y, int rows, int cols, int keyValue);

#endif /* SEARCHOPS_H */