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
	// student Han = { 20171704, "Han", 3.3 }; ����ü���� char�κ� �̷��� �����ϸ� �ȵǰ� strcpy����Ѵ�.
	student Han;
	student* pHan;
	pHan = &Han;


	Han.id = 704; strcpy(Han.name, "Sang Han"); Han.gradePoints = 3.3;				// . �� �̿��ؼ� ����
	printf("%d//%s//%f \n", Han.id, Han.name, Han.gradePoints);

	//(*pHan).id �� ���� ���� ���������� ���ٵ� �����ϳ� �Ǽ��� ������ ũ�� �׳� ->����.
	pHan->id = 705; strcpy(pHan->name, "Sang Woo Han"); pHan->gradePoints = 3.4;  // -> �� �̿��ؼ� ����
	printf("%d//%s//%f \n", pHan->id, pHan->name, Han.gradePoints);					   // -> �� �̿��ؼ� ��µ� ����                     


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

	STAMP start = { { 2009, 1, 26 }, { 10, 30, 20 } };							//�̷������� �ʱ�ȭ ����
	printf("%d-%d-%d \n", start.date.year, start.date.month, start.date.day);	// . ���ӻ������ ���ٵ� ����

	struct Student {
		int id;
		char name[26];
		double gradePoints;
	};

	struct Student std[50];                       //struct���� []�� �̷��� typedef�� ��� �� ������ ��� �����ѵ�
	struct Student* pStd;
	pStd = std;                                   //�̷��� �迭�� �������ǰ���ε� ���� ����

	int n = 50;
	struct Student* list;
	list = (struct Student*)malloc(sizeof(struct Student) * n); //�����Ҵ����� �ִ°͵� ����

	return 0;
}