#include "BarcodeReader.h"


/*char* signalDecoder(char* signalBC){
    int i = 0;
    char* decodedSignal;
    while (signalBC[i]!='\0'){
        if (signalBC[i] == '1') {
            i++;
        }
        else if(signalBC[i] == signalBC[i+1]) {
            if (signalBC[i+1] == signalBC[i+2]) {
                i+=2;
            }
            else {
                decodedSignal[i] = '1';
            }
        }
        else {
                decodedSignal[i] = '0';
        }
    }
}*/