#include "BarcodeReader.h"
#include "Defines.h"
#include "Vector.h"

char* signalDecoder(Vector* decoded, char* signalBC) {
    vectorInit(decoded, strlen(signalBC));
    int i = 0, j = 0;
    char *decodedSignal = (char*)malloc(strlen(signalBC)*sizeof(char));
    while (signalBC[i] != '\0') {
        if (signalBC[i] == '1') {
            i++;
            continue;
        }
        else if(signalBC[i] == signalBC[i+1]) {
            if (signalBC[i+1] == signalBC[i+2]) {
                vectorPush(decoded, 'e');
                i+=2;
                //printf("Bar Code cannot be read!\n");
                //exit(1);
               while (!vectorIsEmpty(decoded)){
                    char temp[5];
                    for (int i = 0; i<5;i++){
                        temp[i] = vectorPop(decoded);
                    }
                }
                    char temp[5];
                while (decodedSignal[i]!='\0') {
                    for (int i = 0; i<5 ;i++) {
                        temp[i] = decodedSignal[i];
                    }
                }
                //FIXME Check for error solution for noise
            }
            else {
                vectorPush(decoded, '1');
               // decodedSignal[j] = '1';
               // i += 2, j++;
            }
        }
        else {
                vectorPush(decoded, '0');
                decodedSignal[j] = '0';
                i++, j++;
        }
    }
    // for (int i=0; i<strlen(decodedSignal);i++){
    //     if (i%5==0)
    //         printf(" ");
    //     printf("%c", decodedSignal[i]);
    // }
    printf("%s\n", decoded->items);
    //TODO free the undecoded signal
    return decodedSignal;
}

