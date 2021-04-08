#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SWAP(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int list[], int n)
{
	int i, j, min, temp;

	for (i = 0; i < n - 1; i++)
	{
		min = i;

		for (j = i + 1; j < n; j++)
		{
			if (list[j] < list[min])
			{
				min = j;

			}
			SWAP(&list[i], &list[min]);
		}
	}

}

int main()
{
	int num = 0, step = 10;
	int *a, *temp;
	double duration = 0;
	long rep_all = 0;

	FILE* fp = fopen("lab1_1000.txt", "r");

	if (fp == NULL)
	{
		printf("Error!! :: null file");
		return 0;
	}

	fscanf(fp, "%d", &num);

	a = (int*)malloc(sizeof(int)*num);
	temp = (int*)malloc(sizeof(int)*num);

	for(int i =0; i < num; i++)
	{
		fscanf(fp, "%d", &a[i]);
	}

	fclose(fp);


	printf("Input	: ");
	for (int i = 0; i < num; i++)
	{
		printf("%d ", a[i]);
		temp[i] = a[i];
	}
	printf("\n");

	printf("     num   repetitions     time\n");
	
	for(int n = num; n <= 1000; n+=step)
	{
	    long rep = 0;

	    for(int i = 0; i < num; i++)
	    {
		a[i] = temp[i];
	    }

	    clock_t start = clock();

	    while(clock() - start < 1000)
	    {
		rep++;

		for(int i = 0; i < num; i++)
		{
		    /*for(int j = 0; j < num; j++)
		    {
			a[j] = temp[j];
		    }
		    */
		   // 예제처럼 worst case초기화를 안에서 해 준다면 duration증가한다

		    sort(a, num);
		}
	    }
		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		duration /= rep;

		if(n >= 100)
		{
	    		step = 100;
		}
		rep_all++;
	}

	printf("%6d	%9d	%f\n", num, rep_all, duration);
	
	printf("Sorted : ");
	for(int i = 0; i < num; i++)
	{
	    printf("%d ", a[i]);
	}
	printf("\n");

	free(a);
	free(temp);

	return 0;
}
