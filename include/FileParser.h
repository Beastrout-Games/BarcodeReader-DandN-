#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

FILE* fileLoader(const char* fileName);
char* signalReader(FILE* signalFile);
void fileClose(FILE* fp);

#endif /* FILEPARSER_H */