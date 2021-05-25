#include "StringOps.h"

/**
 * @brief Slice the whole string in groups of 5 and pass it to a array of strings
 */
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

/**
 * @brief  Reverses a given string
 */
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