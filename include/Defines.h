#ifndef _DEFINES_H_
#define _DEFINES_H_

#define INPUT_FORMAT "%f "
#define INITIAL_CAPACITY 50

#define BC_ONE_UNIT_SIZE 5
#define BC_STRING_UNIT_SIZE 6
#define TABLE_SIZE 12

#include <errno.h>
#define CHECK_ALLOCATION_ERR(ptr) \
            if ((ptr) == NULL) { \
                printf("Failed to allocate memory.\n"); \
                exit(ENOMEM); \
            }

#define ZERO        "00001"
#define ONE         "10001"
#define TWO         "01001"
#define THREE       "11001"
#define FOUR        "00101"
#define FIVE        "10100"
#define SIX         "01100"
#define SEVEN       "00011"
#define EIGHT       "10010"
#define NINE        "10000"
#define DASH_TEN    "00100"
#define START_STOP  "00110"

#endif /* _DEFINES_H_ */