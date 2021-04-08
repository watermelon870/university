#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

typedef struct node
{
	int data;
	struct node* next;
}QUEUE_NODE;

typedef struct
{
	QUEUE_NODE* front;
	int count;
	QUEUE_NODE* rear;
}QUEUE;

bool enqueue(QUEUE* queue, int dataIn)
{
	QUEUE_NODE* newPtr = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
	newPtr->data = dataIn;
	newPtr->next = NULL;
	if (queue->count == 0)
	{
		queue->front = newPtr;
	}
	else
	{
		queue->rear->next = newPtr;
	}
	queue->count++;
	queue->rear = newPtr;
	printf("enqueue success! \n");
	return true;
}

bool dequeue(QUEUE* queue)
{
	int dataOut;
	QUEUE_NODE* deleteLoc;

	if (!queue->count)
	{
		return false;
	}
	dataOut = queue->front->data;
	printf("dequeue : %d \n", dataOut);
	deleteLoc = queue->front;
	if (queue->count == 1)
	{
		queue->rear = queue->front = NULL;
	}
	else
	{
		queue->front = queue->front->next;
	}
	queue->count--;
	free(deleteLoc);



	return true;
}

void printAll(QUEUE* queue)
{
	QUEUE_NODE* curr = queue->front;
	while (curr != queue->rear->next)       //이 부분 조심하기
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\nQueue Level : %d\n", queue->count);

}

int main()
{
	QUEUE* pQueue = (QUEUE*)malloc(sizeof(QUEUE));

	if (!pQueue)
	{
		printf("Error allocating queue\n");
	}
	pQueue->front = NULL;
	pQueue->count = 0;
	pQueue->rear = NULL;

	enqueue(pQueue, 1);
	printAll(pQueue);
	enqueue(pQueue, 2);
	printAll(pQueue);
	enqueue(pQueue, 3);

	printAll(pQueue);

	dequeue(pQueue);

	printAll(pQueue);

	return 0;

}

