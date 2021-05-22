#include "FileParser.h"
#include "Defines.h"
#include <stdbool.h>

FILE* fileLoader(const char* fileName) {
	FILE* barCodeInp = NULL;

	barCodeInp = fopen(fileName, "r");
	//FIXME Make error checks for unit tests
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
	inputString = (char*)malloc((signalLength) * sizeof(char*));
	//FIXME Add Error handling
	if (inputString == NULL){
		printf("Could not allocate memory!\n");
        exit(ENOMEM);
	}

	char c[MAX_FLOAT_CHAR];
    float d = 0.0;
	
	while(!feof(signalFile)) {
        fscanf(signalFile,INPUT_FILE_FORMAT, c);
        d = atof(c);

        if(d < 0.5) {
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