#include "BarcodeOps.h"

int barcodeTranslate(const char* fileName) {
    FILE* barCodeFile = NULL;
    char* inputBC;
    char* translatedBC;
    int * decodedBC;
    
    barCodeFile = fileLoader(fileName);
    inputBC = signalReader(barCodeFile);
    translatedBC = signalDecoder(inputBC);
    decodedBC = decodeNumbers(translatedBC);
    
    if (decodedBC[0]==6) {
        translatedBC = reverseStr(translatedBC);
        decodedBC = decodeNumbers(inputBC);
    }

    free (decodedBC);
    free (inputBC);
    free (translatedBC);
    return 0;
}
