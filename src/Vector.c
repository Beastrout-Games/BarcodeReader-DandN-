#include <stdlib.h>
#include "Vector.h"

/**
 * @brief initialization of vector struct variable
 * 
 * @param vec pointer to vector struct variable
 * @param initialCapacity initial number of elements in the vector
 */
void vectorInit(Vector *vec, size_t initialCapacity)
{
  vec->capacity = initialCapacity;
  vec->size = 0;
  vec->items = malloc(sizeof(char) * vec->capacity);
}

/**
 * @brief return the size of the vector
 * 
 * @param v pointer of type struct vector
 * @return returns curent number of elements
 */
int vectorGetSize(Vector *v)
{
  return v->size;
}

/**
 * @brief checks if there is no elements
 * 
 * @param vec pointer of type struct vector
 * @return true if it's empty 
 * @return false if elemts are available
 */
bool vectorIsEmpty(Vector *vec)
{
  return vec->size == 0;
}

/**
 * @brief Re-allocated memory if the max capaity is reached.
 * 
 * @param vec pointer to struct from type vector
 * @param capacity maximum number of elements in the vector
 */
void vectorResize(Vector *vec, size_t capacity)
{
  char *items = realloc(vec->items, sizeof(char) * capacity);
  if (items)
  {
    vec->items = items;
    vec->capacity = capacity;
  }

  if (vec->size >= capacity)
  {
    vec->size = capacity;
  }
}

/**
 * @brief adds elements
 * 
 * @param vec pointer to struct from type vector
 * @param item element
 */
void vectorPush(Vector *vec, char item)
{
  if (vec->capacity == vec->size)
  {
    vectorResize(vec, vec->capacity * 2);
  }
  vec->items[vec->size] = item;
  vec->size++;
}

/**
 * @brief sets item pointer to current ship
 * 
 * @param vec pointer to struct from type vector
 * @param idx ship index
 * @param item element array pointer
 */
void vectorSet(Vector *vec, size_t idx, char item)
{
  if (idx < vec->size)
  {
    vec->items[idx] = item;
  }
}

/**
 * @brief takes the current ship index
 * 
 * @param vec pointer to struct from type vector
 * @param idx ship index
 * @return if ships exist return ship index, otherwise return void pointer (NULL) 
 */
char vectorGet(Vector *vec, size_t idx)
{
  if (idx < vec->size)
  {
    return vec->items[idx];
  }
  return 'e';
}

/**
 * @brief Gets last element
 * 
 * @param vec pointer to struct from type vector
 * @return return void pointer if it's empty
 */
char vectorBack(Vector *vec)
{
  if (0 == vec->size)
  {
    return 'e';
  }

  return vec->items[vec->size - 1];
}

/**
 * @brief deletes one element and reorders the vector array
 * 
 * @param vec pointer to struct from type vector
 * @param idx ship index
 */
void vectorDelete(Vector *vec, size_t idx)
{
  if (idx >= vec->size)
  {
    return;
  }
 free(vec->items);
 vec->items = NULL;
}

/**
 * @brief takes out a vector element
 * 
 * @param vec pointer to struct from type vector
 */
char vectorPop(Vector *vec)
{
  char temp = 'e';
  if (vec->size == 0)
  {
    printf("Error in popping a vector!");
    exit(1);
  }
  temp = vectorBack(vec);
  vec->size--;
  return temp;
}

/**
 * @brief frees the allocated memory for the vector 
 * 
 * @param vec pointer to struct from type vector
 */
void vectorFree(Vector *vec)
{
  if (vec->items != NULL)
  {
    free(vec->items);
    vec->items = NULL;
    vec->size = 0;
    vec->capacity = 0;
  }
}

void vectorReset(Vector *vec)
{
  if (vec->items != NULL)
  {
    free(vec->items);
    vec->items = NULL;
    vec->size = 0;
    vec->capacity = INITIAL_CAPACITY;
    vec->items =(char*)malloc(vec->capacity * sizeof(char));
  }
}