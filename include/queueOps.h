#ifndef QUEUEOPS_H
#define QUEUEOPS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct qNode qNode;
typedef struct queue queue;

/**
 * @brief Allocates memory and initialises a Node for the queue data structure.
 *        Returns a pointer to the initialised Queue.
 *
 * @param keyValue Value to be enqued
 * @param row The row coordinate of the value in the matrix
 * @param col The col coordinate of the value in the matrix
 * @return qNode*
 */
qNode* NodeInit(char keyValue, int row, int col);

/**
 * @brief Get the Value object. Returns the enqued value.
 *
 * @param baseNode Pointer to a Node from the Queue
 * @return char
 */
char getValue(qNode* baseNode);

/**
 * @brief Get the Row object. Returns the row coordinate in the matrix of the
 *        enqueued value.
 *
 * @param baseNode Pointer to a Node from the Queue
 * @return int
 */
int getRow(qNode* baseNode);

/**
 * @brief Get the Col object. Returns the col coordinate in the matrix of the
 *        enqueued value.
 *
 * @param baseNode Pointer to a Node from the Queue
 * @return int
 */
int getCol(qNode* baseNode);

/**
 * @brief Set the Value object of a Node to be enqueued.
 *
 * @param baseNode  Pointer to a Node from the Queue
 * @param keyValue  Value from the Matrix to be enqueued
 */
void setValue(qNode* baseNode, char keyValue);

/**
 * @brief Set the Row object of a Node to be enqueued.
 *
 * @param baseNode  Pointer to a Node from the Queue
 * @param row  Row coordinate of the value to be enqueued
 */
void setRow(qNode* baseNode, int row);

/**
 * @brief Set the Col object of a Node to be enqueued.
 *
 * @param baseNode Pointer to a Node from the Queue
 * @param col Col coordinate of the value to be enqueued
 */
void setCol(qNode* baseNode, int col);

/**
 * @brief Allocates memory and initialises a Queue as linked list.
 *        Returns a pointer to the initialised Queue.
 *
 * @return queue*
 */
queue* QueueInit();

/**
 * @brief Adds a Node to the Queue's back. If Queue is empty it will
 *        set both front and back of the Queue to the first node.
 *
 * @param baseQueue Pointer to a Queue
 * @param baseNode Pointer to a Node to be added
 */
void Enqueue(queue* baseQueue, qNode* baseNode);

/**
 * @brief Removes a Node from the Queue's front. If this was the only node,
 *        the function will empty and reset the Queue.
 *
 * @param baseQueue Pointer to a Queue
 */
void Dequeue(queue* baseQueue);

/**
 * @brief Checks if a Queue is empty (no Nods inside it). Returns true if
 *        the Queue is indeed empty; false otherwise
 *
 * @param baseQueue Pointer to a Queue to be verified.
 * @return true
 * @return false
 */
bool isEmpty(queue* baseQueue);

/**
 * @brief Get the Front object in a Queue. Returns a pointer to the
 *        frontmost Node.
 *
 * @param baseQueue Pointer to a Queue
 * @return qNode*
 */
qNode* getFront(queue* baseQueue);

/**
 * @brief Get the Back object in a Queue. Returns a pointer to the
 *        last enqueued Node.
 *
 * @param baseQueue Pointer to a Queue
 * @return qNode*
 */
qNode* getBack(queue* baseQueue);

/**
 * @brief Get the size value of a Queue. Returns the number of
 *        enqueued elements (Nodes).
 *
 * @param baseQueue Pointer to a Queue
 * @return int
 */
int getSize(queue* baseQueue);

/**
 * @brief Prints the contents of a Queue (all enqueued values)
 *
 * @param baseQueue Pointer to a Queue.
 */
void printQueue(queue* baseQueue);

#endif /* QUEUEOPS_H */