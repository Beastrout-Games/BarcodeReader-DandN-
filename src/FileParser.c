#include "FileParser.h"
#include "Defines.h"
#include <stdbool.h>

FILE* fileLoader(const char* fileName) {
	FILE* barCodeInp = fopen(fileName, "r");
	//FIXME Make error checks for unit tests
	if (barCodeInp == NULL){
        printf("Could not open the file!\n");
        exit(ENOENT);
    }
	return barCodeInp;
}

char* signalReader(FILE* signalFile){
	int singnalLength = 0, i = 0;
	
	fscanf(signalFile, "%d", &singnalLength);
	// printf("%d\n", singnalLength);
	char* inputString = (char*)malloc(singnalLength * sizeof(char));
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
	fileClose(signalFile);
	return inputString;
}

void fileClose(FILE* fp) {
	fclose(fp);
	fp = NULL;
}