#ifndef BARCODEREADER_H
#define BARCODEREADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void printBarCode (int * decoded, int size);
char* signalDecoder(char* signalBC);

#endif /* BARCODEREADER_H */