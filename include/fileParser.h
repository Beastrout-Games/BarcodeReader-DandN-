#ifndef FILEPARSER_H
#define FILEPARSER_H

/**
 * @brief Reads a file vcontaining the data for the Matrix and fills it.
 *        First line of the file are the rows and cols sizes.
 *        Rest of the file is the matrix data.
 * 
 * @param argv Name of the file to parse.
 * @param rows Pointer to the rows variable to set
 * @param cols Pointer to the cols variable to set
 * @return char**  - Pointer to the already set and fille din matrix
 */
char** parseData(char *argv, int *rows, int *cols);

#endif /* FILEPARSER_H */