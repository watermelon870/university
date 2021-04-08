#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int data;
	struct _node *link;
}NODE;

NODE* searchNode(NODE* head, int data)          //찾는 위치 찾기
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
NODE* findnode(NODE* head, int data)        //searchNode와 같은 기능 수행
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

void addNode(NODE * head, int place, int data)   //원하는 위치 뒤에 넣기
{
	NODE* mid = searchNode(head, place);
	if(mid == NULL)
	{
		return;                                  //place값을 LINKED LIST에서 찾지 못한 경우 그냥 함수 종료
	}

	NODE *newNode = (NODE *)malloc(sizeof(NODE));//step1. 새로운 노드 만들기
	newNode->data = data;                        //step2. 새로운 노드에 데이터 대입
	newNode->link = mid->link;                   //step3. 새로운 노드와 뒷노드 연결
	mid->link = newNode;                         //step4. 새로운 노드와 앞노드 연결

	printf("data inserted \n");
}

void addNodeBefore(NODE * head, int place, int data)   //원하는 위치 앞에 넣기 ※이 때 앞 뒤 연결이 조금 어렵다
{
	NODE* next = head->link;
	NODE* prev = head;
	while(next != NULL && next->data != place)    //여러가지 고려해서 짜줘야한다, ※한 줄 틀리면 ㅂㅂㅂ이다 ※진짜다
	{
		prev = next;             //place 값을 갖는 NODE 배정
		next = next->link;       //next의 앞 값을 배정
	}

	if(next == NULL)                             //place 값이 없는 경우
	{
		return;
	}

	NODE *newNode = (NODE *)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->link = next;
	prev->link = newNode;

	printf("data inserted \n");
}

void addNodeToFirst(NODE* head, int data)   //앞에 데이터값 추가
{
	NODE *newNode = (NODE *)malloc(sizeof(NODE));  //데이터 저장할 새로운 노드 만들기
	newNode->data = data;						   //데이터값 저장
	newNode->link = head->link;					   //새로운 노드와 head노드의 뒤에있는 노드 연결
	head->link = newNode;						   //새로운 노드와 head노드 연결

	printf("data inserted \n");
}

void addNodeToLast(NODE *head, int data) //맨 뒤에 데이터값 추가
{
	NODE* last = head;
	while(last->link != NULL)
	{
		last = last->link;
	}                              //맨 뒤 값 찾기

	NODE *newNode = (NODE *)malloc(sizeof(NODE));   //데이터 저장할 새로운 노드 만들기
	newNode->data = data;          //새로운 노드에 데이터값 입력
	last->link = newNode;          //맨 마지막 뒤에와 새로운 노드 연결
	newNode->link = NULL;          //새로운 노드 뒤에 NULL처리

	printf("data inserted \n");
}

void freeList(NODE* head)
{
	NODE* next = head;
	NODE* prev;                   //노드 2개로 관리. 앞에것은 지워주고 뒤에것은 계속 유지하며 순서 알려주는 용도
	while(next->link != NULL)
	{
		prev = next;
		next = next->link;        //계속 앞에것과 뒤에것 하나씩 배정됨
		free(prev);               //앞에것 계속 free해주기
	}
	free(next);                   //마지막 남은 하나 free
}

/* printList와 같은 기능 수행
NODE* curr = head->link;
while(curr != NULL)
{
printf("%d ", curr->data);
curr = curr->link;
}
*/
void printList(NODE* head)        //왜 데이터가 깨져서 나오지???
{
	NODE* last = head;
	while(last->link != NULL)
	{
		last = last->link;        //이거 추가해줘서 무한루프는 빠져나옴 
							      //앞쪽에 추가해줘야 head->data에 있는 쓰레기값이 아닌 정상적인 값이 출력된다
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