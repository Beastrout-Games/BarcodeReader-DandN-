#include <stdio.h>
#include "publicAPI.h"

int main(int argc, char **argv){
    //TODO "Usage docstring"
    for (int i = 1; i<argc; i++) {
        barcodeTranslate(argv[i]);
	}

    return 0;
}