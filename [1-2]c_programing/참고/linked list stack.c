#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { false, true } bool;
//없어서 직접 정의해야된데...

typedef struct
{
	int count;
	struct node* top;
}STACK;

typedef struct node
{
	int data;
	struct node* link;
}STACK_NODE;

bool Push(STACK* pStack, int dataIn)
{
	STACK_NODE* pNew;
	bool success;

	pNew = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if (!pNew)
	{
		success = false;
	}
	else
	{
		pNew->data = dataIn;
		pNew->link = pStack->top;
		pStack->top = pNew;
		pStack->count++;

		success = true;
	}
	return success;
}

bool Pop(STACK* pStack)
{
	int dataOut;
	STACK_NODE* pDlt;
	bool success;

	if (pStack->top)
	{
		success = true;
		dataOut = pStack->top->data;
		printf("Poped data : %d \n", dataOut);

		pDlt = pStack->top;
		pStack->top = (pStack->top)->link;
		pStack->count--;

		free(pDlt);
	}
	else
	{
		success = false;
	}
	return success;
}

void printAll(STACK* pStack)
{
	STACK_NODE* curr = pStack;
	while (curr->link != NULL)
	{
		curr = curr->link;
		printf("%d ", curr->data);
	}
	printf("\n");

}

int main()
{
	STACK* pStack;
	pStack = (STACK*)malloc(sizeof(STACK));
	pStack->top = NULL;
	pStack->count = 0;

	Push(pStack, 1);
	printAll(pStack);
	Push(pStack, 2);
	printAll(pStack);
	Push(pStack, 3);
	printAll(pStack);

	Pop(pStack);
	printAll(pStack);

	return 0;
}