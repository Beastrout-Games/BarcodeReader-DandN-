#include "queueOps.h"

struct qNode {
	char NodeValue;
	int row;
	int col;
	struct qNode* Next;
};

struct queue {
	struct qNode* front;
	struct qNode* back;
};

static void setQueueEnds(queue* baseQueue);

/*NODE OPERATIONS START HERE*/
qNode* NodeInit(char keyValue, int row, int col) {
	struct qNode* baseNode = (qNode*)malloc(sizeof(qNode));
	baseNode->NodeValue = keyValue;
	baseNode->row = row;
	baseNode->col = col;
	baseNode->Next = NULL;

	return baseNode;
}

char getValue(qNode* baseNode) {
	return baseNode->NodeValue;
}

int getRow(qNode* baseNode) {
	return baseNode->row;
}

int getCol(qNode* baseNode) {
	return baseNode->col;
}

void setValue(qNode* baseNode, char keyValue) {
	baseNode->NodeValue = keyValue;
}

void setRow(qNode* baseNode, int row) {
	baseNode->row = row;
}

void setCol(qNode* baseNode, int col) {
	baseNode->col = col;
}

/* QUEUE OPERATIONS START HERE*/
queue* QueueInit() {
	queue* baseQueue = (queue*)malloc(sizeof(queue));
	setQueueEnds(baseQueue);

	return baseQueue;
}

void Enqueue(queue* baseQueue, qNode* baseNode) {
	if (isEmpty(baseQueue)) {
		baseQueue->back = baseNode;
		baseQueue->front = baseNode;
	}
	else {
		baseQueue->back->Next = baseNode;
		baseQueue->back = baseNode;
	}
}

void Dequeue(queue* baseQueue) {
	if (isEmpty(baseQueue)) {
		printf("The queue is empty. Nothing to de-queue!\n");

		return;
	}
	if (baseQueue->front->Next == NULL) {
		qNode* tempNode = baseQueue->front;
		setQueueEnds(baseQueue);
		free(tempNode);
	}
	else {
		qNode* tempNode = baseQueue->front;
		baseQueue->front = baseQueue->front->Next;
		tempNode->Next = NULL;
		free(tempNode);
	}
}

bool isEmpty(queue* baseQueue) {
	if (baseQueue->back == NULL) {
		return true;
	}
	else {
		return false;
	}
}

qNode* getFront(queue* baseQueue) {
	return baseQueue->front;
}

qNode* getBack(queue* baseQueue) {
	return baseQueue->back;
}

int getSize(queue* baseQueue) {
	int counter = 0;
	qNode* counterPtr = baseQueue->front;
	while (counterPtr != NULL) {
		counterPtr = counterPtr->Next;
		counter++;
	}

	return counter;
}

void printQueue(queue* baseQueue) {
	if (isEmpty(baseQueue)) {
		printf("The queue is empty. Nothing to print!\n");

		return;
	}

	qNode* counterPtr = baseQueue->front;
	while (counterPtr->Next != NULL) {
		printf("%c ", counterPtr->NodeValue);
		counterPtr = counterPtr->Next;
	}
	printf("\n");
}

void setQueueEnds(queue* baseQueue) {
	baseQueue->back = NULL;
	baseQueue->front = baseQueue->back;
}