#include "FileParser.h"
#include "Defines.h"
#include <stdbool.h>

FILE* fileLoader(const char* fileName) {
	FILE* barCodeInp = fopen(fileName, "r");
	//FIXME Make error checks for unit tests
	if (barCodeInp == NULL){
        printf("Could not open the file!\n");
        exit(1);
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
        exit(1);
	}

	char c[MAX_FLOAT_CHAR];
    float d;

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

// int formulaC() {
// 	int sum = 0;
// 	int n; // number of symbols(after the conversion) -> lenght of the new arr
// 	int Wc; //weight of a symbol

// 	for(int i = 1; i <= n; i++) {
// 		//Wc = current symbol from the array
// 		//Wc = arr[i - 1]
// 		sum += ((((n - i) % 10) + 1) * Wc) % 11;
// 	}
// 	return sum;
// }

// int formulaK() {
// 	int sum = 0;
// 	int n;
// 	int Wc;

// 	for(int i = 1; i <= n+1; i++) {
// 		//Wc = current symbol from the array
// 		//Wc = arr[i - 1]
// 		sum += ((((n - i + 1) % 9) + 1) * Wc) % 11;
// 	}
// 	return sum;
// }