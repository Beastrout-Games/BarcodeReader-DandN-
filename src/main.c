#include <stdio.h>
#include "BarcodeReader.h"
#include "BarcodeDecoder.h"
#include "StringOps.h"

int main(int argc, char **argv){
    char* inputBC = NULL;
    char* translatedBC = NULL;
    int * decodedBC = NULL;
    int sizeOfCode = 0;
    
    scanf("%d", &sizeOfCode);
    inputBC = signalReader(sizeOfCode);

    translatedBC = signalDecoder(inputBC);
    free (inputBC);

    decodedBC = decodeNumbers(translatedBC);
    if (decodedBC[0]==6) {
        translatedBC = reverseStr(translatedBC);
        decodedBC = decodeNumbers(translatedBC);
    }

    sizeOfCode = strlen(translatedBC) / BC_ONE_UNIT_SIZE;
    printBarCode(decodedBC, sizeOfCode);
    free (translatedBC);
    free (decodedBC);
    
    return 0;
}