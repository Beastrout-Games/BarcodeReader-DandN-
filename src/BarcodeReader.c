#include "BarcodeReader.h"
#include "Defines.h"
#include "Vector.h"

char* signalReader(int sizeOfInput) {
	char* inputString = NULL;

	inputString = (char*)malloc((sizeOfInput + 1) * sizeof(char));
	if (inputString == NULL){
		printf("Could not allocate memory!\n");
        exit(ENOMEM);
	}

	float d = 0.0;
	for(int i = 0; i < sizeOfInput-1; i++) {
		scanf(INPUT_FORMAT, &d);
		//Hardcoded for now(waiting for smarter solution)
        if(d < 0.47) {
			inputString[i] = '0';
        }
        else {
			inputString[i] = '1';
        }
	}
	inputString[sizeOfInput] = '\0'; 
	return inputString;
}