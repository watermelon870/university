#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *s1 = "15.1234";
	int num1;
	double num2;
	float num3;
	//���ڿ� -> ����
	num1 = atoi(s1); //stdlib.h�� ���� �Ǵ� atoi�Լ�. ���ڿ� �� int�κ��� ��ȯ�� �ش�. ���н� return 0
	num2 = atof(s1); //stdlib.h�� ���� �Ǵ� atof�Լ�. ���ڿ� �� double�κ��� ��ȯ�� �ش�. ���н� return 0;
	num3 = strtof(s1, NULL); //atoi�� float ����, �ٸ����� endptr�� ���� ��� �Ѵٴ� ���̴�.

	printf("%d//%lf//%f\n", num1, num2, num3);

	//���� -> ���ڿ�
	char s2[20];			 //����� ū ũ��� �迭�� ���� �� ��� ����â���� ������ ���� �ʴ´�
	float num4 = 283.123;

	sprintf(s2, "%f", num4); //int�� ��� %d, �Ǽ��� ��� %f�� �ٲ��ֱ⸸ �ϸ� ���밡��

	printf("%s\n", s2);

	return 0;
}