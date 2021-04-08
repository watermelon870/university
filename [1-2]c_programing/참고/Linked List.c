#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int Data;				//데이터를 저장할 맴버
	struct _NODE *next;		//다음 노드의 주소를 저장할 포인터

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
	free(pCur);                        //이런식으로 사용하면 되는구나
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

NODE* insertNode(NODE *pList, NODE *pPre, int data)  //Linear 리스트에 node삽입하기, NODE* 인자 2개 사용
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

	//free(pNew);                    외않됨...
	return pList;
}

NODE* findnode(NODE* head, int data)        //Linked list 탐색하는 방법
{
	NODE* curr;

	curr = head;
	while (curr != NULL)
	{
		if (curr->Data == data)break;
		curr = curr->next;
	}
	//free(curr);                      외않됨...
	return curr;

}

int main()
{
	/*array와 비교했을 때 linked list가 가지는 장점 - > array는 원소의 검색에서 
	유리하지만 원소의 삽입 및 삭제가 어렵다. 그래서 데이터의 추가및 삭제가 빈번하고
	크기가 정해지지 않은 경우 유용하다*/

	/*HEAD pointer
		DATA + LINK - > DATA + LINK --- DATA + LINK
	-> NULL
	의 형식을 갖고 있다*/

	//head pointer 생성
	NODE *head = malloc(sizeof(NODE));	

	//node1에 10, node2에 20배정
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

	NODE *curr = head->next;		//연결 리스트 순회용 포인터에 첫 번째 노드의 주소 저장
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