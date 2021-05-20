#include <stdio.h>
#include <math.h>
#include "FileParser.h"

int main(int argc, char **argv){
    FILE* barCodeFile = NULL;

    for (int i = 1; i<argc; i++) {
		barCodeFile = fileLoader(argv[i]);
        signalReader(barCodeFile);
	}
}

