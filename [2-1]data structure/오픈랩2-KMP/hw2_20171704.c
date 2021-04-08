#include <stdio.h>
#include <string.h>

//pattern�� string�� ������� �ִ� 100���� ����
#define max_string_size 100
#define max_pattern_size 100

int failure[max_pattern_size];
char string[max_string_size];
char pat[max_pattern_size];

//KMP�˰���
int pmatch(char *string, char *pat)
{
	int i = 0, j = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);

	//i�� lens, j�� lenp�� ���� ��
	while (i < lens && j < lenp)
	{
		//string[i]�� pat[j]�� ���� ��� �� �� ���� char��
		if (string[i] == pat[j])
		{
			i++;
			j++;
		}
		//j�� 0�� ���̽�, string[i+1]�� pat[j]�� ��
		else if (j == 0)
		{
			i++;
		}
		//string[i]�� pat[j]�� match���� �ʴ� ���, failure function�� �̿��ؼ� ���� ���� matching point�� �̵��Ѵ�
		else
		{
			j = failure[j - 1] + 1;
		}
	}
	
	return ((j == lenp) ? (i - lenp) : -1);
}

//failure function
void fail(char *pat)
{
	int i, n = strlen(pat);
	failure[0] = -1;

	//pat[0]~pat[j]������ ���ο� �� �������� �ؼ�
	//���ο� ������ suffix�� prefix�� ���ؼ� pat[0]~pat[i] = pat[j-i]~pat[j] �����ϴ� i�� ����
	for (int j = 1; j < n; j++)
	{
		i = failure[j - 1];	
		
		while ((pat[j] != pat[i + 1]) && (i >= 0))
		{
			i = failure[i];
		}
	
		if (pat[j] == pat[i + 1])
		{
			failure[j] = i + 1;
		}

		else
		{
			failure[j] = -1;
		}
	}
}

int main()
{
	//kmp.txt���� string�� pat��������
	FILE* fp = fopen("kmp.txt", "r");

	if (fp == NULL)
	{
		printf("Error!! :: NULL FILE!\n");
	}
	else
	{
		fgets(string, sizeof(string), fp);
		fgets(pat, sizeof(pat), fp);
	}
	fclose(fp);

	//failure function�� ���� failure[i]�� ����
	fail(&pat);

	//print�ϸ� pmatch����
	printf("%d\n", pmatch(&string, &pat));

	return 0;
}