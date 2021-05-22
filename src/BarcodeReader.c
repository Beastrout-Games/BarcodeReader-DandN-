#include "BarcodeReader.h"
#include "Defines.h"
#include "Vector.h"

char* signalDecoder(char* signalBC) {
    Vector rawSignal = {NULL, 0, 0};
    Vector decodedSignal = {NULL, 0, 0};
    size_t stringLength = strlen(signalBC);
    vectorInit(&rawSignal, stringLength);
    vectorInit(&decodedSignal, INITIAL_CAPACITY);
    int i = 0;
    while (signalBC[i] != '\0') {
        do {
            vectorPush(&rawSignal, signalBC[i]);
            i++;
        } while (vectorBack(&rawSignal) == signalBC[i]);

        switch (vectorBack(&rawSignal)) {
            case '1':
                vectorReset(&rawSignal);
                break;

            case '0':
                if (vectorGetSize(&rawSignal)==1) {
                    vectorPush(&decodedSignal, '0');
                    continue;
                }
                else if (vectorGetSize(&rawSignal)==2){
                    vectorPush(&decodedSignal, '1');
                    continue;
                }
                else {
                    for(int j=0; j < vectorGetSize(&rawSignal); j++) {
                        vectorPush(&decodedSignal,'e');
                    }
                }
                break;

            default:
                printf("Incorrectly parsed barcode string!");
                exit(1);
                break;
        }
    
    //TODO free the undecoded signal
    }
    char* tempString = (char*)malloc(sizeof(char*)* (stringLength));
    strcpy(tempString, decodedSignal.items);
    strncpy(tempString,decodedSignal.items,stringLength);
    vectorFree(&rawSignal);
    vectorFree(&decodedSignal);
    return tempString;
}

