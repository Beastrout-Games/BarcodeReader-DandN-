#ifndef VECTOR_H_
#define VECTOR_H_

#include <stddef.h>
#include <stdbool.h>
#include <errno.h>

typedef struct Stack{
  char *items;
  size_t capacity;
  size_t size;
} Stack;


void vectorInit(Stack *vec, int initialCapacity);
int vectorGetSize(Stack *vec);
bool vectorIsEmpty(Stack *vec);
void vectorResize(Stack *vec, size_t newSize);
void vectorPush(Stack *vec, void *elem);
void vectorSet(Stack *vec, size_t idx, void *elem);
void* vectorGet(Stack *vec, size_t idx);
void* vectorBack(Stack *vec);
void vectorDelete(Stack *vec, size_t idx);
void vectorPop(Stack *vec);
void vectorFree(Stack *vec);
void *vectorGetLast(Stack *vec);

#endif /* VECTOR_H_ */