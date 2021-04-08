#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[20];
	char mail[20];
	int mobile;
}professor;

typedef struct {
	char name[20];
	char major[10];
	int ID;
	float cgpa;
}student;

typedef struct {
	char type;
	union {
		professor prof;
		student stu;			//각각 위에서 정의된 structure을 불러온다             
		//두가지가 배타적인 관계를 가질 때 union타입 사용 가능(메모리 낭비 방지)
	}u;
}person;

int main()
{
	int i = 0;
	person data[2];               //prof와 stu중 무엇인지 아직 모르기때문에 person으로 생각

	//데이터 치환
	data[0].type = 'p';
	strcpy(data[0].u.prof.name, "Kim");
	strcpy(data[0].u.prof.mail, "kim@sognag.ac.kr");
	data[0].u.prof.mobile = 1234567;

	data[1].type = 's';
	strcpy(data[1].u.stu.name, "Chulsoo");
	strcpy(data[1].u.stu.major, "cs");
	data[1].u.stu.ID = 20171704;
	data[1].u.stu.cgpa = 3.4;
	
	//출력
	for (i = 0; i < 2; i++)
	{
		switch (data[i].type) {
		case'p' :
			printf("professor %s\n", data[i].u.prof.name);
			printf("%s, %d\n", data[i].u.prof.mail, data[i].u.prof.mobile);
			break;
		case's':
			printf("(%s) %d\n", data[i].u.stu.major, data[i].u.stu.ID);
			printf("%s\nCGPA : %f\n", data[i].u.stu.name, data[i].u.stu.cgpa);
			break;
		}
	}
	printf("\n");
	return 0;
}