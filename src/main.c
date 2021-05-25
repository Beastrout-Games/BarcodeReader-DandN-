#include <stdio.h>
#include "PublicAPI.h"

int main(int argc, char **argv){
    for (int i = 1; i<argc; i++) {
        barcodeTranslate(argv[i]);
	}
    
    return 0;
}