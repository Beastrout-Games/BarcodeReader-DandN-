#include "searchOps.h"

static queue* validationQueue;
static qNode* valueNode;
static int** verifiedMatrix;
static char** readMatrix;
static const int rowDir[4] = { 0, 1,  0, -1 };
static const int colDir[4] = { 1, 0, -1,  0 };

void longestPath(char* argv) {
	int rows = 0;
	int cols = 0;
	int longestPath = 0;
	int currentPath = 0;

	validationQueue = QueueInit();
	readMatrix = parseData(argv, &rows, &cols);
	verifiedMatrix = matrixInit(rows, cols);

	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			if (!verifiedMatrix[x][y]) {
				verifiedMatrix[x][y] = 1;
				valueNode = NodeInit(readMatrix[x][y], x, y);
				Enqueue(validationQueue, valueNode);
				currentPath = searchBFS(rows, cols);
				if (currentPath > longestPath) {
					longestPath = currentPath;
				}
			}
		}
	}
	printf("\nlongest path = %d\n", longestPath);
	matrixDelete(readMatrix, rows);
	matrixDelete(verifiedMatrix, rows);
	free(validationQueue);
}

int searchBFS(int rows, int cols) {
	int row = 0;
	int col = 0;
	char keyValue = 'E';
	int pathLen = 0;
	qNode* tempNode;

	while (!isEmpty(validationQueue)) {
		tempNode = getFront(validationQueue);
		row = getRow(tempNode);
		col = getCol(tempNode);
		keyValue = getValue(tempNode);
		checkNeighbors(row, col, rows, cols, keyValue);
		Dequeue(validationQueue);
		pathLen++;
	}

	return pathLen;
}

void checkNeighbors(int x, int y, int rows, int cols, int keyValue) {
	qNode* tempNode = NULL;
	int adjX = 0;
	int adjY = 0;

	for (int i = 0; i < DIRECTIONS; i++) {
		adjX = x + rowDir[i];
		adjY = y + colDir[i];
		if (isValid(adjX, adjY, rows, cols, keyValue)) {
			verifiedMatrix[adjX][adjY] = 1;
			tempNode = NodeInit(keyValue, adjX, adjY);
			Enqueue(validationQueue, tempNode);
			tempNode = NULL;
		}
	}
}

bool isValid(int x, int y, int rows, int cols, int keyValue) {
	if (x < 0 || y < 0 || x >= rows || y >= cols) {
		return false;
	}
	if (verifiedMatrix[x][y]) {
		return false;
	}
	if (readMatrix[x][y] != keyValue) {
		return false;
	}
	return true;
}