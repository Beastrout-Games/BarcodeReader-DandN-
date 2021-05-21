#ifndef VECTOR_H_
#define VECTOR_H_

#include <stddef.h>
#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include "Defines.h"

typedef struct Vector{
  char *items;
  size_t capacity;
  size_t size;
} Vector;


void vectorInit(Vector *vec, size_t initialCapacity);
int vectorGetSize(Vector *vec);
bool vectorIsEmpty(Vector *vec);
void vectorResize(Vector *vec, size_t newSize);
void vectorPush(Vector *vec, char item);
void vectorSet(Vector *vec, size_t idx, char item);
char vectorGet(Vector *vec, size_t idx);
char vectorBack(Vector *vec);
void vectorDelete(Vector *vec, size_t idx);
char vectorPop(Vector *vec);
void vectorFree(Vector *vec);
void *vectorGetLast(Vector *vec);
void vectorReset(Vector *vec);

#endif /* VECTOR_H_ */