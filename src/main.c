#include <stdio.h>
#include <math.h>
#include "FileParser.h"
#include "BarcodeReader.h"
#include "BarcodeDecoder.h"

int main(int argc, char **argv){
    FILE* barCodeFile = NULL;
    char* sbc;
    //TODO "Usage docstring"
    for (int i = 1; i<argc; i++) {
		barCodeFile = fileLoader(argv[i]);
        sbc = signalReader(barCodeFile);
        sbc = signalDecoder(sbc);
        decodeNumbers(sbc);
	}

    return 0;
}