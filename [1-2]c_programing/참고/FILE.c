#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//���Ͽ� ���ڿ� ���� - fprintf
	FILE *fp;
	fp = fopen("hello.txt", "w");				 // hello.txt ������ ������(w)�� ���� 

	fprintf(fp, "%s %d\n%d", "Hello", 100, 200); //����("%s %d\n")�� �����Ͽ� ���ڿ��� ���Ͽ� ����

	fclose(fp);									 //������ ���� �޸� �Ҵ��̶� free���� �����͸� �ݾƾ��Ѵ�.

	//���Ͽ��� ���ڿ� �б� - fscanf
	char s1[10];
	int num1;
	int num2;

	FILE *fp1 = fopen("hello.txt", "r");			 //hello.txt ������ �б���(r)�� ����

	fscanf(fp1, "%s %d %d", s1, &num1, &num2);

	printf("%s %d %d \n", s1, num1, num2);

	fclose(fp1);

	//���Ͽ� ���ڿ� ���� - fputs
	FILE* fp2 = fopen("hello.txt", "w");

	fputs("Hello, World!", fp2);					//������ �������� �ʰ� ��� �� �� �ִ� ����

	fclose(fp2);

	//���Ͽ��� ���ڿ� ���� - fwrite
	FILE *fp3 = fopen("hello.txt", "w");

	fwrite(s1, strlen(s1), 1, fp3);					// fwrite(���ڿ�, ���� ũ��, ���� Ƚ��, ����������)

	fclose(fp3);

	//���Ͽ��� ���ڿ� �������� - fgets
	char buffer[20];                                // �Ѿ�� �׳� �� �޴� ������ ������ ������ ������ �������� �ʴ´�

	FILE *fp4 = fopen("hello.txt", "r");            // ������ ������ \n�̹Ƿ� ��������

	fgets(buffer, sizeof(buffer), fp4);

	fputs(buffer, stdout);

	fclose(fp4);

	//���Ͽ��� ���ڿ� �������� - fread�� �ʱ����� ó�������� �Ƚ��϶�

	return 0;
}