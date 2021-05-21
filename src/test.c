#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
void reverseStr(const char* s1, char *s2, size_t len) {
    int i, j;
    for(i = len - 1, j = 0; i >= 0; i--, j++) {
        s2[j] = s1[i];
    }
    s2[j] = '\0';
}

int main() {

//formula C-----------------------------------
    int n = size;
    int sum = 0;
    int Wc;
    //int K1 = 2, C1 = 5;

    for(int i = 1; i <= n; i++) {
        Wc = decodedNumbers[i - 1];
        sum += (((n - i) % 10) + 1) * Wc;
    }
    sum = sum % 11;
    int C = sum;
    printf("C: %d\n", sum);

//-------------------------------------------

//formula K----------------------------------
    n = size;
    sum = 0;
    Wc = 0;

    for(int i = 1; i <= n + 1; i++) {
        if (i <= n) {
            Wc = decodedNumbers[i - 1];
        }
        else {
            Wc = C;
        }
        
        sum += ((((n - i + 1)) % 9) + 1) * Wc;
    }
    sum = sum % 11;

    printf("K: %d\n", sum);

    return 0;
}
//------------------------------------------*/