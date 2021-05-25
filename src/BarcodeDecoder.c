#include "BarcodeDecoder.h"
#include "BarcodeValidation.h"
#include "StringOps.h"
#include "Vector.h"

char *signalDecoder(char *signalBC)
{
    Vector rawSignal = {NULL, 0, 0};
    Vector decodedSignal = {NULL, 0, 0};
    __uint8_t stringLength = 0;

    stringLength = strlen(signalBC);
    vectorInit(&rawSignal, stringLength);
    vectorInit(&decodedSignal, INITIAL_CAPACITY);
    int i = 0;
    while (signalBC[i] != '\0') {
        do {
            vectorPush(&rawSignal, signalBC[i]);
            i++;
        } while (vectorBack(&rawSignal) == signalBC[i]);

        switch (vectorBack(&rawSignal)) {
        case '1':
            vectorReset(&rawSignal);
            break;

        case '0':
            if (vectorGetSize(&rawSignal) == 1) {
                vectorPush(&decodedSignal, '0');
                continue;
            }
            else if (vectorGetSize(&rawSignal) == 2) {
                vectorPush(&decodedSignal, '1');
                continue;
            }
            else {
                for (int j = 0; j < vectorGetSize(&rawSignal); j++) {
                    vectorPush(&decodedSignal, 'e');
                }
            }
            break;

        default:
            printf("Incorrectly parsed barcode string!");
            exit(1);
            break;
        }
    }
    vectorPush(&decodedSignal, '\0');

    char *tempString = NULL;
    tempString = (char *)malloc(sizeof(char *) * (stringLength + 1));
    strncpy(tempString, decodedSignal.items, stringLength);
    vectorFree(&rawSignal);
    vectorFree(&decodedSignal);
    return tempString;
}

int *decodeNumbers(char *code) {
    int size = strlen(code) / BC_ONE_UNIT_SIZE;
    char **slicedCode = NULL;
    int *decodedNumbers = (int *)malloc(size * sizeof(int));
    slicedCode = (char **)matrixInit(size, BC_STRING_UNIT_SIZE);
    sliceString(code, slicedCode, size);

    char *table[TABLE_SIZE] = {
        ZERO, ONE, TWO, THREE, FOUR, FIVE,
        SIX, SEVEN, EIGHT, NINE, DASH_TEN, START_STOP};

    //after start/stop are removed
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            if (strcmp(slicedCode[i], table[j]) == 0) {
                decodedNumbers[i] = j;
            }
        }
    }
    matrixDelete((void **)slicedCode, size);
    return decodedNumbers;
}

void printBarCode(int *decoded, int size) {
    int codeStatus = isValidCode(decoded, size);

    if (codeStatus == VALID_CODE) {
        printf("The barcode scanned is:\n");
        for (int i = 1; i < size - 3; i++) {
            if (decoded[i] == 10) {
                printf("- ");
                continue;
            }
            printf("%d ", decoded[i]);
        }
        printf("\n");
    }
    else {
        printErrorStatus(codeStatus);
    }
}