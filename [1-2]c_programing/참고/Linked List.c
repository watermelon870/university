#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int Data;				//�����͸� ������ �ɹ�
	struct _NODE *next;		//���� ����� �ּҸ� ������ ������

}NODE;

NODE* deleteNode(NODE* pList, NODE* pPre, NODE* pCur)
{
	if (pPre == NULL)
	{
		pList = pCur->next;
	}
	else
	{
		pPre->next = pCur->next;
	}
	free(pCur);                        //�̷������� ����ϸ� �Ǵ±���
	printf("data deleted \n");

	return pList;
}

void insertNode_head(NODE *head, int data)
{
	NODE* pNew;
	pNew = (NODE *)malloc(sizeof(NODE));
	pNew->Data = data;
	pNew->next = head->next;

	head->next = pNew;

	printf("data inserted \n");
}

NODE* insertNode(NODE *pList, NODE *pPre, int data)  //Linear ����Ʈ�� node�����ϱ�, NODE* ���� 2�� ���
{
	NODE* pNew;
	pNew = (NODE *)malloc(sizeof(NODE));

	pNew->Data = data;
	if (pPre == NULL)
	{	
		pNew->next = pList;
		pList = pNew;
	}
	else
	{
		pNew->next = pPre->next;
		pPre->next = pNew;
	}

	printf("data inserted \n");

	//free(pNew);                    �ܾʵ�...
	return pList;
}

NODE* findnode(NODE* head, int data)        //Linked list Ž���ϴ� ���
{
	NODE* curr;

	curr = head;
	while (curr != NULL)
	{
		if (curr->Data == data)break;
		curr = curr->next;
	}
	//free(curr);                      �ܾʵ�...
	return curr;

}

int main()
{
	/*array�� ������ �� linked list�� ������ ���� - > array�� ������ �˻����� 
	���������� ������ ���� �� ������ ��ƴ�. �׷��� �������� �߰��� ������ ����ϰ�
	ũ�Ⱑ �������� ���� ��� �����ϴ�*/

	/*HEAD pointer
		DATA + LINK - > DATA + LINK --- DATA + LINK
	-> NULL
	�� ������ ���� �ִ�*/

	//head pointer ����
	NODE *head = malloc(sizeof(NODE));	

	//node1�� 10, node2�� 20����
	NODE *node1 = (NODE *)malloc(sizeof(NODE));
	head->next = node1;
	node1->Data = 10;

	NODE *node2 = (NODE *)malloc(sizeof(NODE));
	node1->next = node2;
	node2->Data = 20;

	node2->next = NULL;

	insertNode(node2->next, node2, 30);                  //insertNode
	insertNode_head(head, 0);
	deleteNode(head, head, head->next);

	NODE *curr = head->next;		//���� ����Ʈ ��ȸ�� �����Ϳ� ù ��° ����� �ּ� ����
	while (curr != NULL)
	{
		printf("%d\n", curr->Data);
		curr = curr->next;
	}

	//printf("data found on : %p \n", findnode(head, 30)); //findNode

	free(node2);
	free(node1);
	free(head);

	return 0;
}