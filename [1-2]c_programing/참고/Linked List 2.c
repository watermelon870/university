#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int data;
	struct _node *link;
}NODE;

NODE* searchNode(NODE* head, int data)          //ã�� ��ġ ã��
{
	NODE* last = head;
	while(last->link != NULL)
	{
		last = last->link;
		if(last->data == data)
		{
			printf("Data found! \n");
			return last;
		}
	}

	printf("Data not found! \n");
	return NULL;
}
/*
NODE* findnode(NODE* head, int data)        //searchNode�� ���� ��� ����
{
	NODE* curr;

	curr = head;
	while(curr != NULL)
	{
		if(curr->data == data)break;
		curr = curr->link;
	}

	return curr;

}
*/

void addNode(NODE * head, int place, int data)   //���ϴ� ��ġ �ڿ� �ֱ�
{
	NODE* mid = searchNode(head, place);
	if(mid == NULL)
	{
		return;                                  //place���� LINKED LIST���� ã�� ���� ��� �׳� �Լ� ����
	}

	NODE *newNode = (NODE *)malloc(sizeof(NODE));//step1. ���ο� ��� �����
	newNode->data = data;                        //step2. ���ο� ��忡 ������ ����
	newNode->link = mid->link;                   //step3. ���ο� ���� �޳�� ����
	mid->link = newNode;                         //step4. ���ο� ���� �ճ�� ����

	printf("data inserted \n");
}

void addNodeBefore(NODE * head, int place, int data)   //���ϴ� ��ġ �տ� �ֱ� ���� �� �� �� ������ ���� ��ƴ�
{
	NODE* next = head->link;
	NODE* prev = head;
	while(next != NULL && next->data != place)    //�������� ����ؼ� ¥����Ѵ�, ���� �� Ʋ���� �������̴� ����¥��
	{
		prev = next;             //place ���� ���� NODE ����
		next = next->link;       //next�� �� ���� ����
	}

	if(next == NULL)                             //place ���� ���� ���
	{
		return;
	}

	NODE *newNode = (NODE *)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->link = next;
	prev->link = newNode;

	printf("data inserted \n");
}

void addNodeToFirst(NODE* head, int data)   //�տ� �����Ͱ� �߰�
{
	NODE *newNode = (NODE *)malloc(sizeof(NODE));  //������ ������ ���ο� ��� �����
	newNode->data = data;						   //�����Ͱ� ����
	newNode->link = head->link;					   //���ο� ���� head����� �ڿ��ִ� ��� ����
	head->link = newNode;						   //���ο� ���� head��� ����

	printf("data inserted \n");
}

void addNodeToLast(NODE *head, int data) //�� �ڿ� �����Ͱ� �߰�
{
	NODE* last = head;
	while(last->link != NULL)
	{
		last = last->link;
	}                              //�� �� �� ã��

	NODE *newNode = (NODE *)malloc(sizeof(NODE));   //������ ������ ���ο� ��� �����
	newNode->data = data;          //���ο� ��忡 �����Ͱ� �Է�
	last->link = newNode;          //�� ������ �ڿ��� ���ο� ��� ����
	newNode->link = NULL;          //���ο� ��� �ڿ� NULLó��

	printf("data inserted \n");
}

void freeList(NODE* head)
{
	NODE* next = head;
	NODE* prev;                   //��� 2���� ����. �տ����� �����ְ� �ڿ����� ��� �����ϸ� ���� �˷��ִ� �뵵
	while(next->link != NULL)
	{
		prev = next;
		next = next->link;        //��� �տ��Ͱ� �ڿ��� �ϳ��� ������
		free(prev);               //�տ��� ��� free���ֱ�
	}
	free(next);                   //������ ���� �ϳ� free
}

/* printList�� ���� ��� ����
NODE* curr = head->link;
while(curr != NULL)
{
printf("%d ", curr->data);
curr = curr->link;
}
*/
void printList(NODE* head)        //�� �����Ͱ� ������ ������???
{
	NODE* last = head;
	while(last->link != NULL)
	{
		last = last->link;        //�̰� �߰����༭ ���ѷ����� �������� 
							      //���ʿ� �߰������ head->data�� �ִ� �����Ⱚ�� �ƴ� �������� ���� ��µȴ�
		printf("%d ", last->data);
		
	}
}

int main()
{
	NODE *head = (NODE *)malloc(sizeof(NODE));
	head->link = NULL;

	addNodeToLast(head, 1);
	addNodeToLast(head, 2);
	addNodeToLast(head, 3);
	addNodeToLast(head, 4);
	addNodeToLast(head, 5);

	//addNode(head, 3, 10);
	//addNode(head, 100, 10);
	//addNodeBefore(head, 3, 10);

	/*
	addNodeToFirst(head, 1);
	addNodeToFirst(head, 2);
	addNodeToFirst(head, 3);
	*/

	printList(head);

	freeList(head);

	return 0;
}