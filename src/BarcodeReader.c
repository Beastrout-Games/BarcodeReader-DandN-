#include "BarcodeReader.h"
#include "Defines.h"
#include "Vector.h"

char* signalDecoder(char* signalBC) {
    Vector decoded;
    Vector decodedSignal;
    vectorInit(&decoded, strlen(signalBC));
    vectorInit(&decodedSignal, INITIAL_CAPACITY);
    int i = 0;
    while (signalBC[i] != '\0') {
        do {
            vectorPush(&decoded, signalBC[i]);
            i++;
        } while (vectorBack(&decoded) == signalBC[i]);

        switch (vectorBack(&decoded)) {
            case '1':
                vectorReset(&decoded);
                break;

            case '0':
                if (vectorGetSize(&decoded)==1) {
                    vectorPush(&decodedSignal, '0');
                    continue;
                }
                else if (vectorGetSize(&decoded)==2){
                    vectorPush(&decodedSignal, '1');
                    continue;
                }
                else {
                    for(int j=0; j < vectorGetSize(&decoded);j++) {
                        vectorPush(&decodedSignal,'e');
                    }
                }
                break;

            default:
                printf("Incorrectly parsed barcode string!");
                exit(1);
                break;
        }
    // for (int i=0; i<strlen(decodedSignal);i++){
    //     if (i%5==0)
    //         printf(" ");
    //     printf("%c", decodedSignal[i]);
    // }
    //TODO free the undecoded signal
    }
    char* tempString = decodedSignal.items;
    return tempString;
}

