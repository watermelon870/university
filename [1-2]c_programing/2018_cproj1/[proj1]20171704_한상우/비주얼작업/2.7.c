#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **result;
int idx = 1;

void find_func(int result_n, char *dArr, char *kArr, char *tArr, char *tpll)
//2������ �ƴ� array�� ���ٴ� ���� ����. �� �Լ����� ��ū�� ������ �� � �ൿ�� ���ϴ��� ����
{
	char *temp = (char *)malloc(sizeof(char) * 20);

	tArr = tArr + 1;                                        //�� ������ tArr�κ��� �����ؼ� ���� "{"�� �߶��ִ� ����.

	if (strncmp(tArr, "for", 3) == 0)                       //�ݺ���
	{
		printf("for��\n");
	}
	else if (strncmp(tArr, "if", 2) == 0)	//if��, else��
	{
		printf("if��\n");
	}
	else if (strncmp(tArr, "@", 1) == 0)
	{
		printf("idx\n");
	}
	else if (strstr(tpll, "{") == NULL)     //�ܼ� ������ ġȯ Ư���� ���(�� �ٿ� 2�� ���� �ܼ� ������ ġȯ)
	{
		*(result + result_n) = strcat(*(result + result_n - 1), dArr);
	}
	else									//�ܼ� ������ ġȯ
	{
		temp = strtok(tpll, "{");
		*(result + result_n) = strtok(NULL, "{");
		temp = strcat(temp, dArr);
		*(result + result_n) = strcat(temp, *(result + result_n) + strlen(kArr) + 1);
	}										//���� ���� ��������ϸ� ���� line2���� 0�� 1�� ����ȴ�. Ȯ���ϰ� print�ϰ� �ϱ�

	//free(temp);                           //����� ���� �� �ߴ°žߤ÷��ؤ����äĤ��ɤ�
}

void what_to_do(int count, char **dArr, char **kArr, char **tArr, char **tpll)
{

	int t_num = 1;
	int k_num = 0;
	int d_num = 0;
	int line_n = 0;
	int result_n = 0;
	char *temp = (char *)malloc(sizeof(char) * 20);          //tpll����� array

	for (t_num; t_num <= count; t_num++)                     //t_num(t_Arr���� ����)�� �������� ����Ŵ� �ݺ���
	{
		if (strstr(*(tpll + line_n), "{") == NULL)           //tpl���� {}�� �ϳ��� ���� ���� result�� �׷��� �־���
		{
			*(result + result_n) = *(tpll + line_n);
			line_n++;
			result_n++;
		}
		else												//tpll���� {}�� �ִ� �κ�. n���� ���� ���� ������ ����
		{
			temp = *(tpll + line_n);
			find_func(result_n, *(dArr + d_num), *(kArr + k_num), *(tArr + t_num), *(tpll + line_n));
			*(result + result_n) = temp;
			strtok(*(tpll + line_n), "}");
			temp = strtok(NULL, "}");

			if (strstr(*(tpll + line_n), "{") == NULL)  //tpll���� {}�� �ϳ��� ���
			{
				temp = *(tpll + line_n);
				find_func(result_n, *(dArr + d_num), *(kArr + k_num), *(tArr + t_num), *(tpll + line_n)); //�� �׷��� �𸣰����� result���� temp��(�ּ�)�� ���� return �´٤̤� �����Լ��� �Űܺ��� ������ �״�� �߻��Ѵ�
				result_n++;
				d_num++;
				k_num++;
				t_num++;
				line_n++;
			}
			else										//tpll���� {}�� �ϳ��̻��� ���
			{
				while (1)
				{
					temp = *(tpll + line_n);
					find_func(result_n, *(dArr + d_num), *(kArr + k_num), *(tArr + t_num), *(tpll + line_n));
					*(tpll + line_n) = strstr(*(tpll + line_n) + 1, "{");
					result_n++;
					d_num++;
					k_num++;
					t_num++;
					if (strstr(*(tpll + line_n) + 1, "{") == NULL)
					{
						line_n++;
						break;
					}

				}
			}
		}

	}
	//free(temp);
}

int main()
{
	result = (char **)malloc(sizeof(char *) * 25);
	*result = (char *)malloc(sizeof(char) * (25 * 50));
	for (int i = 1; i < 25; i++)
	{
		*(result + i) = *(result + i - 1) + 50;
	}      //��� ������� ���� �� 2���� �迭. �ִ� 25�� ����
	
	/*
	char tpl[1024] = "Hi {name}, your id is {id}\nItems that you have is following.\nITEM LIST:\n{for items}\nItem{@idx}\nName:{name}\nPrice:{price}{if price_type=='KR'}KRW{else}USD{/if}\n\n{for}";
	char data[1024] = "name=beak\nid=1512\nitems.count=2\nitems[0].name=Apple\nitems[0].price=1000\nitems[0].price_type=KR\nitems[1].name=Banana\nitems[1].price=2\nitems[1].price_type=USD";
	*/                                         //������ �� ����ߴ� �κ�          

	char **dArr;
	dArr = (char **)malloc(sizeof(char *) * 25);
	*dArr = (char *)malloc(sizeof(char) * (25 * 50));
	for (int i = 1; i < 25; i++)
	{
		*(dArr + i) = *(dArr + i - 1) + 50;
	}      //datal�� "=" �޺κ��� �����ϴ� 2���� array. �ִ� 25�� ���� ����

	char **kArr;
	kArr = (char **)malloc(sizeof(char *) * 25);
	*kArr = (char *)malloc(sizeof(char) * (25 * 50));
	for (int i = 1; i < 25; i++)
	{
		*(kArr + i) = *(kArr + i - 1) + 50;
	}      //datal�� "=" �պκ��� �����ϴ� 2���� array. �ִ� 25�� ���� ����

	char **tArr;
	tArr = (char **)malloc(sizeof(char *) * 20);
	*tArr = (char *)malloc(sizeof(char) * (20 * 50));
	for (int i = 1; i < 20; i++)
	{
		*(tArr + i) = *(tArr + i - 1) + 50;
	}     //{}��ū ������ �����ϴ� 2���� array.

	int line_n = 0;     //tpl�̳� datal���� �ɰ����� �� ��  

	const char **tpll;
	tpll = (char **)malloc(sizeof(char *) * 10);
	*tpll = (char *)malloc(sizeof(char) * (10 * 100));
	for (int i = 1; i < 10; i++)
	{
		*(tpll + i) = *(tpll + i - 1) + 100;
		
	}                   //tpl ���� �ɰ����� ���� �����ϴ� 2���� array. �ִ� 10�� ���� ����



	*(tpll + line_n) = strtok(tpl, "\n");
	while (1)
	{

		if (*(tpll + line_n) == NULL)
		{
			break;
		}
		line_n++;
		*(tpll + line_n) = strtok(NULL, "\n");
		//printf("%s \n", *(tpll + line_n));                    tpll �� ������������ Ȯ��
	}					//tpl�� ������ ���� line�� tpll[line_n]�� ����



	line_n = 0;         //line_n ��Ȱ���� ���ؼ� �ʱ�ȭ
	int tArr_n = 0;     //line_n�� {}������ �ݵ�� ��ġ�ϴ� ���� �ƴϱ⶧���� ���� ���� ����
	int count = 2;
	while (1)
	{
		
		if (*(tpll + line_n) == NULL)
		{
			break;
		}
		if (strstr(*(tpll + line_n), "{") == NULL)
		{
			line_n++;
		}
		else
		{
			tArr_n++;
			*(tArr + tArr_n) = strstr(*(tpll + line_n), "{");

			if (strstr(*(tArr + tArr_n) + 1, "{") == NULL)
			{


				line_n++;
				count++;
			}
			else
			{
				while (1)
				{
					if (strstr(*(tArr + tArr_n) + 1, "{") == NULL)
					{
						break;
					}
					tArr_n++;
					*(tArr + tArr_n) = strstr(*(tArr + tArr_n - 1) + 1, "{");
					count++;
				}

				line_n++;
			}
		}


	}                   //tArr[1] ~ tArr[count]���� ��� {}���� ���� �� ����.�� ����� �������� �ƴϹǷ� �Լ����� ����Ҷ� �� �ٵ� ����Ұ� ��
	/*
	for (int i = 1; i <= count; i++)
	{
		printf("%s \n", *(tArr + i));
	}
	*/                  //tArr �� ������������ Ȯ��

	char **datal;
	datal = (char **)malloc(sizeof(char *) * 25);
	*datal = (char *)malloc(sizeof(char) * (25 * 100));
	for (int i = 1; i < 25; i++)
	{
		*(datal + i) = *(datal + i - 1) + 100;
	}                   //data ���� �ɰ����� ���� �����ϴ� 2���� array. �ִ� 25�� ���� ����



	line_n = 0;         //line_n ��Ȱ���� ���ؼ� �ʱ�ȭ
	*(datal + line_n) = strtok(data, "\n");
	while (1)
	{
		if (*(datal + line_n) == NULL)
		{
			break;
		}

		line_n++;
		*(datal + line_n) = strtok(NULL, "\n");

	}                 //data�� �� ���� ������ ���� line�� datal[line_n]�� ���� 


	line_n = 0;       //line_n ��Ȱ���� ���ؼ� �ʱ�ȭ
	*(kArr + line_n) = strtok(*(datal + line_n), "=");
	dArr[line_n] = strtok(NULL, "=");
	while (1)
	{
		//printf("%s=%s \n", *(kArr + line_n), *(dArr + line_n));    kArr�� dArr�� ������������ Ȯ��
		if (*(datal + line_n) == NULL)
		{
			break;
		}

		line_n++;
		*(kArr + line_n) = strtok(*(datal + line_n), "=");
		*(dArr + line_n) = strtok(NULL, "=");
		

	}                           //data �� "="�� �� ���� dArr�� ����, "key"�պκ��� kArr�� ����.


	 
	//what_to_do(count, dArr, kArr, tArr, tpll, result);       //what_to_do �Լ����� find_func�Լ��� ȣ���ϸ� �̻��ϰ� result�� temp�� ���� ���� �Ǿ ���ƿ´�. �������� ���� �Ұ���

	
	find_func(0, *dArr, *kArr, *(tArr + 1), *tpll);
	find_func(1, *(dArr + 1), *(kArr + 1), *(tArr + 2), *tpll);
	printf("%s\n", *(result));
	                               //beak�� ���ؼ� �� �� �� ���������� �Ǵ� �κ�..

	free(result);
	free(*result);
	free(datal);
	free(*datal);
	free(dArr);
	free(*dArr);
	free(kArr);
	free(*kArr);
	free(tArr);
	free(*tArr);
	free(tpll);
	free(*tpll);						//�����Լ����� ����� �����Ҵ� ��� free�Ϸ�

	return 0;
}