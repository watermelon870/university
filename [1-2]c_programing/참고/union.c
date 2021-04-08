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
		student stu;			//���� ������ ���ǵ� structure�� �ҷ��´�             
		//�ΰ����� ��Ÿ���� ���踦 ���� �� unionŸ�� ��� ����(�޸� ���� ����)
	}u;
}person;

int main()
{
	int i = 0;
	person data[2];               //prof�� stu�� �������� ���� �𸣱⶧���� person���� ����

	//������ ġȯ
	data[0].type = 'p';
	strcpy(data[0].u.prof.name, "Kim");
	strcpy(data[0].u.prof.mail, "kim@sognag.ac.kr");
	data[0].u.prof.mobile = 1234567;

	data[1].type = 's';
	strcpy(data[1].u.stu.name, "Chulsoo");
	strcpy(data[1].u.stu.major, "cs");
	data[1].u.stu.ID = 20171704;
	data[1].u.stu.cgpa = 3.4;
	
	//���
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