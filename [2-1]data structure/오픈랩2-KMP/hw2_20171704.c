#include <stdio.h>
#include <string.h>

//pattern과 string의 사이즈는 최대 100으로 설정
#define max_string_size 100
#define max_pattern_size 100

int failure[max_pattern_size];
char string[max_string_size];
char pat[max_pattern_size];

//KMP알고리즘
int pmatch(char *string, char *pat)
{
	int i = 0, j = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);

	//i와 lens, j와 lenp를 각각 비교
	while (i < lens && j < lenp)
	{
		//string[i]와 pat[j]가 같은 경우 둘 다 다음 char비교
		if (string[i] == pat[j])
		{
			i++;
			j++;
		}
		//j가 0인 케이스, string[i+1]과 pat[j]을 비교
		else if (j == 0)
		{
			i++;
		}
		//string[i]와 pat[j]가 match하지 않는 경우, failure function을 이용해서 얻은 다음 matching point로 이동한다
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

	//pat[0]~pat[j]까지의 새로운 한 문장으로 해석
	//새로운 문장의 suffix와 prefix를 비교해서 pat[0]~pat[i] = pat[j-i]~pat[j] 만족하는 i값 저장
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
	//kmp.txt에서 string과 pat가져오기
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

	//failure function을 통해 failure[i]값 지정
	fail(&pat);

	//print하며 pmatch실행
	printf("%d\n", pmatch(&string, &pat));

	return 0;
}