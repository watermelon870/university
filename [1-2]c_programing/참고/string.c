#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[20] = "Good day";   // string�� �ƴ� �׳� char �� ���(str1[i]�� ��쵵 �����ؼ�) '~'�� �����ϴ� �ݸ� string�� "~~"�� ����
								 // �迭 ���� �ϸ鼭 �ٷ� ���ڿ� ���ͷ��� �Ҵ��ؾ� ������ ������ �߻����� �ʴ´�!
	char* str1;                   
	str1 = (char *)malloc(sizeof(char) * 10);
	printf("str1 after malloc : ");
	scanf("%s", str1);
	printf("%s", str1);           //���� �Ҵ��� ���� �� �ĸ� ���̵��� �� �ִ�.
	//printf("%d \n", sizeof(str1));  -> 4���
	
	/*
	str1 = "How are you";
	printf("str1 len : %d \n", strlen(str1)); 
								//�׳� str1 = "~~"���� ���� �ʰ� �ϸ� �̻��� ��(1.5��)�� �������� "~~"���� �ϰ� ���� ���������� ��� ����.
	printf("str1 sizeof : %d \n", sizeof(str1));
								//sizeof(str1)�� ������ �����ͺ��� �̹Ƿ� 4byte
	*/

	int count = 1;
	for (count; str1[count] != '\0'; count++)  //"\0"�ƴѰ� ����
	{
		printf("%d ", count);
	}                           //count = �� ���� ���� - 1

	printf("\n");

	printf("str sizeof :%d \nstr len : %d \n", sizeof(str), strlen(str)); //�����ͺ����� �ƴϹǷ� sizeof�� 11, strlen�� ���� �Ҵ�� �κи� ����.

	int array[] = { 6,3,2,9,7,1,5,4,8 };
	const int length = sizeof(array) / sizeof(array[0]); //�̷������� ���� �������� ���� array�� length ���� ����.

														 //char str1[11] = "Hello!";
														 //char str2[11];
														 //str2 = str1; -> ������ ������. �ֳ��ϸ� �ܼ��� �迭�� ���� �ּ��̸� ������ �ƴϴ�. �ּ� �� ���� �Ұ���

	printf("%s//%s\n", str, str + 3);     //string�� pointeró�� ��밡���ϸ� �����ϰ� �ٶ� �� �� �־�� �Ѵ�

	//scanf("%10s", str);
	//printf("%s \n", str); //�翩���� �������� �ν� / %s ��� %[^\n]s�� ����ϸ� ������� �����ؼ� �Է¹ޱ� ����
	
	printf("str fgets : ");
	fgets(str, sizeof(str), stdin);					 // \n���� �Է¹ް� �ڿ� \0�� �߰��� ����� �׷��� strlen���� ���� ũ�⺸�� +1

	printf("%s \n", str);
	printf("str sizeof : %d \n", sizeof(str));
	printf("str len : %d \n", strlen(str));

	printf("str gets : ");
	gets(str);										 // \n�� \0���� ġȯ�Ǿ� ����ȴ�. line�� ���̰� str���� ��� segfault�߻��ϴ� ����
	printf("%s \n", str);
	printf("str sizeof : %d \n", sizeof(str));
	printf("str len : %d \n", strlen(str));			 // �������𿡼��� sizeof�� �Һ��̰� strlen�� ��� �ٲ� �� �ִ�.

	//�������͡ؿ� ���ڿ� ���ͷ�(R-Value)�� ����� ���(���� �ּ�ó���� "~~"�κ�)�� ���б� �����̴�!!!
	//�ݸ鿡 �����Ҵ����� ������ ���ڿ� ���ͷ��� str[0] = 'i'; �̷� ������� ���� ���� �� �ִ�. 
	printf("str1 fgets: ");
	fgets(str1, 20, stdin);                      // int���� sizeof(char)�� 20�̳� �� �־ ��� ����, �ٸ� �������� �ּ�ó���� str1�� "~~"��  ������ �κ��� �־ �� �����µ�
	printf("%s \n", str1);
	printf("str1 sizeof : %d \n", sizeof(str1));
	printf("str1 len : %d \n", strlen(str1));	


	//string.h �Լ� ���

	strlen(str);								// ���̸� ���.
	strcpy(str, str1), strncpy(str, str1, 10);	// �ڿ��Ÿ� �տ��ſ� ����.
	strcmp(str, str1), strncmp(str, str1, 10);	// ���� ���ؼ� +, 0, -�� ���.
	strcat(str, str1), strcat(str, str1, 10);	// �ڿ��Ÿ� �տ��ſ� ���̱�.
	sscanf, sprintf;							// �޸� �� �͵��� �����ͼ� �ൿ
	strstr(str, str1);							// �տ��� �ڿ� �κ��� ã�Ƽ� �ش� �ּ� ��������.
	strchr(str, 'h');                           // ���ڿ����� �˻��� ���� ����. ���� ���ں����� �ּҰ� retrun
	strrchr(str, 'h');                          // ���ڿ� ������(r)���� ���� �˻� ����
	strtok(str, " ");                           // �ڸ� �������� �� ���ڿ��� �߶� return
	//strtok(NULL, " "); �̷��� ��� �� �� �� �ִµ� �̰� �տ��� �ڸ��� ���� �� �κ��� �ǹ��Ѵ�

	/*�ڡ�0xC0000005: 0x013A585D ��ġ�� ����ϴ� ���� �׼��� ������ �߻��߽��ϴ�. -> �� ������ �б� ���� ���� �� �� �߻��Ѵ�.
	��, ���ڿ� ���ͷ��� �Ҵ��ϴ� ��� ���� �޸𸮸� �Ҵ��ϰ� ���ڿ��� �����ϸ� �� ������ �ذ� �� �� �ִ�!!*/

	free(str1);

	return 0;
}