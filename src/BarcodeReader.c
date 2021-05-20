#include "BarcodeReader.h"
#include "Defines.h"

char* signalDecoder(char* signalBC){
    int i = 0, j = 0;
    char *decodedSignal = (char*)malloc(strlen(signalBC)*sizeof(char));
    while (signalBC[i] != '\0'){
        if (signalBC[i] == '1'){
            i++;
            continue;
        }
        else if(signalBC[i] == signalBC[i+1]) {
            if (signalBC[i+1] == signalBC[i+2]) {
                printf("Bar Code cannot be read!\n");
                exit(1);
                //FIXME Check for error solution for noise
            }
            else {
                decodedSignal[j] = '1';
                i += 2, j++;
            }
        }
        else {
                decodedSignal[j] = '0';
                i++, j++;
        }
    }
    // for (int i=0; i<strlen(decodedSignal);i++){
    //     if (i%5==0)
    //         printf(" ");
    //     printf("%c", decodedSignal[i]);
    // }
    return decodedSignal;
}