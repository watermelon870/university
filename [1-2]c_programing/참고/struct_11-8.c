#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	char name[26];
	float gradePoints;
}student;

int main()
{
	// student Han = { 20171704, "Han", 3.3 }; 구조체에서 char부분 이렇게 선언하면 안되고 strcpy써야한다.
	student Han;
	student* pHan;
	pHan = &Han;


	Han.id = 704; strcpy(Han.name, "Sang Han"); Han.gradePoints = 3.3;				// . 을 이용해서 삽입
	printf("%d//%s//%f \n", Han.id, Han.name, Han.gradePoints);

	//(*pHan).id 와 같은 순수 포인터적인 접근도 가능하나 실수의 위험이 크니 그냥 ->쓰자.
	pHan->id = 705; strcpy(pHan->name, "Sang Woo Han"); pHan->gradePoints = 3.4;  // -> 을 이용해서 삽입
	printf("%d//%s//%f \n", pHan->id, pHan->name, Han.gradePoints);					   // -> 을 이용해서 출력도 가능                     


	//Nested Structure
	typedef struct {
		struct {
			int year;
			int month;
			int day;
		}date;
		struct {
			int hour;
			int min;
			int sec;
		}time;
	}STAMP;

	STAMP start = { { 2009, 1, 26 }, { 10, 30, 20 } };							//이런식으로 초기화 가능
	printf("%d-%d-%d \n", start.date.year, start.date.month, start.date.day);	// . 연속사용으로 접근도 가능

	struct Student {
		int id;
		char name[26];
		double gradePoints;
	};

	struct Student std[50];                       //struct에서 []는 이렇게 typedef를 사용 안 했을때 사용 가능한듯
	struct Student* pStd;
	pStd = std;                                   //이렇게 배열과 포인터의관계로도 설정 가능

	int n = 50;
	struct Student* list;
	list = (struct Student*)malloc(sizeof(struct Student) * n); //동적할당으로 주는것도 가능

	return 0;
}