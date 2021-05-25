#include "FileParser.h"
#include "Defines.h"
#include <stdbool.h>

FILE* fileLoader(const char* fileName) {
	FILE* barCodeInp = NULL;

	barCodeInp = fopen(fileName, "r");
	if (barCodeInp == NULL){
        printf("Could not open the file!\n");
        exit(ENOENT);
    }
	return barCodeInp;
}

char* signalReader(FILE* signalFile){
	int signalLength = 0, i = 0;
	char* inputString = NULL;
	
	fscanf(signalFile, "%d", &signalLength);

	inputString = (char*)malloc((signalLength + 1) * sizeof(char));
	if (inputString == NULL){
		printf("Could not allocate memory!\n");
        exit(ENOMEM);
	}

    float d = 0.0;
	while(!feof(signalFile)) {
        fscanf(signalFile, INPUT_FILE_FORMAT, &d);

		//Hardcoded for now(waiting for smarter solution)
        if(d < 0.47) {
			inputString[i] = '0';
        }
        else {
			inputString[i] = '1';
        }
		i++;
	}
	inputString[signalLength] = '\0'; 
	fileClose(signalFile);
	
	return inputString;
}

void fileClose(FILE* fp) {
	fclose(fp);
	fp = NULL;
}