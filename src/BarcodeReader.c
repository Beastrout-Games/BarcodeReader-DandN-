#include "BarcodeReader.h"
#include "Defines.h"
#include "Vector.h"

static char noiseResolve(float* bufferString, char* inputString, int currIndex) {
	float leftDiff, rightDiff;
	char next, prev;

	prev = inputString[currIndex - 1];
	leftDiff = bufferString[currIndex - 1] - bufferString[currIndex];
	
	switch (inputString[currIndex + 1]){
		case 'e':
			next = inputString[currIndex + 2];
			rightDiff = bufferString[currIndex + 2] - bufferString[currIndex];
			break;

		default:
			next = inputString[currIndex + 1];
			rightDiff = bufferString[currIndex + 1] - bufferString[currIndex];
			break;
	}


	switch (prev) {
		case '0':
			if (next == '0'){
				return '1';
			} 
			else {
				if(leftDiff < rightDiff) {
					return '0';
				} 
				else {
					return '1';
				}
			}
			break;
		
		case '1':
			if (next == '1') {
				return '0';
			}
			else {
				if(leftDiff < rightDiff) {
					return '1';
				}
				else {
					return '0';
				}
			}
			break;
	}
}

char* signalReader(int sizeOfInput) {
	char* inputString = NULL;

	inputString = (char*)malloc((sizeOfInput + 1) * sizeof(char));
	if (inputString == NULL){
		printf("Could not allocate memory!\n");
        exit(ENOMEM);
	}
	float* numArr = (float*)malloc(sizeOfInput * sizeof(float));

	float d = 0.0;
	for(int i = 0; i < sizeOfInput-1; i++) {
		scanf(INPUT_FORMAT, &d);
		numArr[i] = d;
	}

	for(int i = 0; i < sizeOfInput -1; i++) {
		//Hardcoded for now(waiting for smarter solution)
		//0.4919 ±0.162 (±32.93%) @ 99.999% confidence level
		//https://bit.ly/3vpqwq3
        if(numArr[i] < 0.3299) {
			inputString[i] = '0';
        }
        else if(numArr[i] > 0.6539) {
			inputString[i] = '1';
        }
		else {
			inputString[i] = 'e';
		}
	}

	for(int i = 0; i < sizeOfInput - 1; i++) {
		if(inputString[i] == 'e') {
			inputString[i] = noiseResolve(numArr, inputString, i);
		}
	}

	inputString[sizeOfInput] = '\0'; 
	return inputString;
}

