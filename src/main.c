#include <stdio.h>
#include "BarcodeReader.h"
#include "BarcodeDecoder.h"
#include "StringOps.h"

int main(void){
    char* inputBC = NULL;
    char* translatedBC = NULL;
    int * decodedBC = NULL;
    int sizeOfCode = 0;
    
    scanf("%d", &sizeOfCode);
    inputBC = signalReader(sizeOfCode);

    translatedBC = signalDecoder(inputBC);
    free (inputBC);

    decodedBC = decodeNumbers(translatedBC);
    if (decodedBC[0] == REVERSED_START_STOP) {
        translatedBC = reverseStr(translatedBC);
        decodedBC = decodeNumbers(translatedBC);
    }

    sizeOfCode = strlen(translatedBC) / BC_ONE_UNIT_SIZE;
    printBarCode(decodedBC, sizeOfCode);

    free (translatedBC);
    free (decodedBC);
    return 0;
}