#include "BarcodeValidation.h"

/**
 * @brief Removes the start/stop and control characters from the bar code in order to verify it against those
 */
static void getCleanCode(int* decoded, int size, int** pureBC) {
	for (int i = 1; i < size - 3; i++) {
		(*pureBC)[i - 1] = decoded[i];
	}
}

/**
 * @brief Formula for the C parameter
 */

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

/**
 * @brief Formula for the K parameter
 */
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

/**
 * @brief Validates that both control parameters are correct.
 * 
 * @param decoded The barcode turned into decimal numbers
 * @param size Size of decoded
 * @return true 
 * @return false 
 */
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

int isValidCode(int* decoded, int size) {
	if (decoded[0] == 11 && decoded[size - 1] == 11 && size > 1) {
		if (checkSumValidation(decoded, size)) {
			printf("Bar-code is correctly scanned!\n");
			return VALID_CODE;
		}
		else { return CHECKSUM_ERR;}
	}
	else if (decoded[0] != 11) { return LEFT_SIDE_ERR;}
	else if (decoded[size] != 11) { return RIGHT_SIZE_ERR;}
	else { return GENERAL_ERROR;}
}

void printErrorStatus(int errnum) {
	switch (errnum) {
		case CHECKSUM_ERR:
			printf("Checksum characters are incorrect/missing!\n");
			break;

		case LEFT_SIDE_ERR:
			printf("Barcode truncated. Move the scanner to the left.\n");
			break;
		
		case RIGHT_SIZE_ERR:
			printf("Barcode truncated. Move the scanner to the right.\n");
			break;
		
		case GENERAL_ERROR:
			printf("Something went wrong! Please restart app and check your barcode!\n");
			break;

		default:
			printf(" :) BSOD");
			break;
	}
	exit(errnum);
}