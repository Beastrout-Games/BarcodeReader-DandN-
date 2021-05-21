#include "BarcodeDecoder.h"

static void getCleanCode(int* decoded, int size, int** pureBC) {
    for (int i= 1; i< size - 3;i++) {
        (*pureBC)[i-1] = decoded[i];
    }
}
//formula C-----------------------------------
static int formulaC(int* pureCode, int size) {
    int n = size - 4;
    int sum = 0;
    int Wc;

    for(int i = 1; i <= n; i++) {
        Wc = pureCode[i - 1];
        sum += (((n - i) % 10) + 1) * Wc;
    }
    sum = sum % 11;
    
    return sum;
}
//-------------------------------------------

static int formulaK(int* pureCode, int size, int C) { 
    int n = size - 4;
    int sum = 0;
    int Wc = 0;

    for(int i = 1; i <= n + 1; i++) {
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
//------------------------------------------*/
static bool checkSumValidation(int* decoded, int size) {
    int C = 0;
    int K = 0;
    int* pureBC = calloc(size, sizeof(int));
    getCleanCode(decoded, size, &pureBC);
    C = formulaC(pureBC, size);
    K = formulaK(pureBC, size, C);

    for (int i= 0; i< 6;i++) {
        printf("%d ", pureBC[i]);
    }
    if ((C == decoded[size - 3]) && (K == decoded[size - 2])) {
        return true;
    }
    else {
        return false;
    }
}

static bool isValidCode(int* decoded, int size) {
    if (decoded[0]==11 && decoded[size-1]==11){     
        if (checkSumValidation(decoded, size)) {
            printf("Bar-code is correctly scanned!\n");
            return true;
        }
        else{
            printf("Checksum characters are not scanned/missing!\n");
            return false;
        }
    }
    else if (decoded[0]!=11) {
        printf("Barcode truncated. Move the scanner to the left.\n");
        return false;
    }
    else{
        printf("Barcode truncated. Move the scanner to the right.\n");
        return false;
    }
}

static void printBarCode (int *decoded, int size) {
    
    if(isValidCode(decoded, size)) {
        printf("The barcode scanned is:\n");
        for (int i=1; i<size - 3; i++) {
            if (decoded[i] == 10) {
                printf("- ");
                continue;
            }
            printf("%d ", decoded[i]);
        }
    }
    else { 
        exit (1); 
    }
}

//slice --------------------------------------
void sliceString(char* code, char** slicedCode, int size){ 
   //TODO create reverse method to be used when the barcode is invalid one way
    /*char code1[strlen(code)];
    reverseStr(code, code1, strlen(code));
    printf("%s\n", code1);*/

    char cut[BC_STRING_UNIT_SIZE];

    for (int i = 0; i < size; i++) {
        for(int j = 0; j < BC_ONE_UNIT_SIZE; j++) {
            static int k = 0;
            cut[j] = code[k++];
        }
        cut[BC_STRING_UNIT_SIZE] = '\0';
        strncpy(slicedCode[i], cut, BC_STRING_UNIT_SIZE);
    }
    //FIXME Remove
    /*check if sliced right*/
}
//---------------------------------------------

int* decodeNumbers(char* code){
//DECODE---------------------------------------
    int size = strlen(code) / BC_ONE_UNIT_SIZE;
    char** slicedCode = malloc(size * sizeof(char*));
    for(int i = 0; i<size; i++){
        slicedCode[i] = malloc(BC_STRING_UNIT_SIZE * sizeof(char*));
    }
    sliceString(code, slicedCode, size);

    int* decodedNumbers = (int*)malloc(size * sizeof(int));
    char *table[TABLE_SIZE] = {
        "00001", "10001", "01001", "11001", "00101", "10100",
        "01100", "00011", "10010", "10000", "00100", "00110"
    };
    //after start/stop are removed
    for(int i = 0; i<size;i++) {
        for(int j = 0; j < TABLE_SIZE; j++) {
            if(strcmp(slicedCode[i], table[j]) == 0) {
                decodedNumbers[i] = j;
            }
        }
    }

    printBarCode(decodedNumbers, size);
    return decodedNumbers;
}
//--------------------------------------------