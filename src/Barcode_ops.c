#include "Barcode_ops.h"

int barcodeTranslate(const char* fileName) {
    FILE* barCodeFile = NULL;
    char* sbc;
    int * dbc;
    
    barCodeFile = fileLoader(fileName);
    sbc = signalReader(barCodeFile);
    sbc = signalDecoder(sbc);
    dbc = decodeNumbers(sbc);
    free (dbc);
    free (sbc);
    return 0;
}

    
