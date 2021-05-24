#include "BarcodeDecoder.h"

static void getCleanCode(int* decoded, int size, int** pureBC) {
	for (int i = 1; i < size - 3; i++) {
		(*pureBC)[i - 1] = decoded[i];
	}
}

static int formulaC(int* pureCode, int size) {
	int n = size - 4;
	int sum = 0;
	int Wc;

	for (int i = 1; i <= n; i++) {
		Wc = pureCode[i - 1];
		sum += (((n - i) % 10) + 1) * Wc;
	}
	sum = sum % 11;

	return sum;
}

static int formulaK(int* pureCode, int size, int C) {
	int n = size - 4;
	int sum = 0;
	int Wc = 0;

	for (int i = 1; i <= n + 1; i++) {
		if (i <= n) {
			Wc = pureCode[i - 1];
		}
		else {
			Wc = C;
		}

		sum += ((((n - i + 1)) % 9) + 1) * Wc;
	}
	sum = sum % 11;

	return sum;
}

static bool checkSumValidation(int* decoded, int size) {
	int C = 0;
	int K = 0;
	int* pureBC = calloc(size, sizeof(int));
	getCleanCode(decoded, size, &pureBC);
	C = formulaC(pureBC, size);
	K = formulaK(pureBC, size, C);
	free(pureBC);

	if ((C == decoded[size - 3]) && (K == decoded[size - 2])) {
		return true;
	}
	else {
		return false;
	}
}

static bool isValidCode(int* decoded, int size) {
	if (decoded[0] == 11 && decoded[size - 1] == 11) {
		if (checkSumValidation(decoded, size)) {
			printf("Bar-code is correctly scanned!\n");
			return true;
		}
		else {
			printf("Checksum characters are not scanned/missing!\n");
			return false;
		}
	}

	return false;
}

static void printErrorStatus(int* decoded) {
	if (decoded[0] != 11) {
		printf("Barcode truncated. Move the scanner to the left.\n");
	}
	else {
		printf("Barcode truncated. Move the scanner to the right.\n");
	}
}

static void printBarCode(int* decoded, int size) {
	if (isValidCode(decoded, size)) {
		printf("The barcode scanned is:\n");
		for (int i = 1; i < size - 3; i++) {
			if (decoded[i] == 10) {
				printf("- ");
				continue;
			}
			printf("%d ", decoded[i]);
		}
		printf("\n");
	}
	else {
		printErrorStatus(decoded);
		exit(1);
	}
}

void sliceString(char* code, char** slicedCode, int size) {
	char cut[BC_STRING_UNIT_SIZE];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < BC_ONE_UNIT_SIZE; j++) {
			static int k = 0;
			cut[j] = code[k++];
		}
		cut[BC_STRING_UNIT_SIZE - 1] = '\0';
		strncpy(slicedCode[i], cut, BC_STRING_UNIT_SIZE);
	}
}

char* reverseStr(char* string) {
    int i, j = 0;
	int len = strlen(string);
	char* tempString = (char*)malloc((len + 1)*sizeof(char));
    for(i = len - 1, j = 0; i >= 0; i--, j++) {
        tempString[j] = string[i];
    }
    tempString[j] = '\0';

	for(i = 0; i <= len; i++){
        string[i] = tempString[i];
    }

	free(tempString);
	tempString = NULL;
	return string;
}

int* decodeNumbers(char* code) {
	int size = strlen(code) / BC_ONE_UNIT_SIZE;
	char** slicedCode = NULL;
	int* decodedNumbers = (int*)malloc(size * sizeof(int));
	slicedCode = (char**)matrixInit(size, BC_STRING_UNIT_SIZE);
	sliceString(code, slicedCode, size);

	char* table[TABLE_SIZE] = {
		"00001", "10001", "01001", "11001", "00101", "10100",
		"01100", "00011", "10010", "10000", "00100", "00110"
	};
	//after start/stop are removed
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < TABLE_SIZE; j++) {
			if (strcmp(slicedCode[i], table[j]) == 0) {
				decodedNumbers[i] = j;
			}
		}
	}
	printBarCode(decodedNumbers, size);
	matrixDelete((void**)slicedCode, size);
	return decodedNumbers;
}