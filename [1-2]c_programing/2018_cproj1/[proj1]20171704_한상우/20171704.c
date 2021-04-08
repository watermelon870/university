#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int idx = 1;              //@idx부분


// 에러 종류
#define E_EXPECTED_CLOSE_BRK -1
#define E_UNPARSABLE_KEY -2
#define E_UNSUPPOERTED_OPERATOR -3
#define E_UNMATCHED_TYPE -4
#define E_UNCLOSED_STATEMENT -5
#define E_KEY_NOT_FOUND -6

// 사용법 출력
void printUsage();
// 결과 문서 렌더링
int render(char*, char*, char**);
//데이터치환, for문, if문, @idx중 어떤 행동을 할지 정해주는 함수
void find_func(int result_n, char *dArr, char *kArr, char *tArr, char *tpll, char **result);
//줄별로 몇번을 반복하는가
void what_to_do(int count, char **dArr, char **kArr, char **tArr, char **tpll, char **result);


/* 기타 전역 함수 및 변수 사용 가능*/
int main(int argc, char** argv) {
	if (argc < 2) {                          
		printUsage();
		return -1;
	}

	// 템플릿 및 데이터 파일 읽기
	FILE* tpl = fopen(argv[1], "r");
	FILE* data = fopen(argv[2], "r");
	if (tpl == NULL) {
		printf("Template File open fail !");
		return -1;
	} if (data == NULL) {
		printf("Data File open fail !");
		return -1;
	}

	const int BUFFER_UNIT = 1024;
	// 파일읽기 위한 임시 메모리 버퍼
	char *readBuf = (char*)malloc(BUFFER_UNIT);
	// Template File 내용. 초기는 1K
	char *tplStr = (char*)malloc(BUFFER_UNIT);
	// Data File 내용. 초기는 1K
	char *dataStr = (char*)malloc(BUFFER_UNIT);
	// Template File 읽기
	int read, total = 0;
	while (feof(tpl) == 0)
	{
		read = fread(tplStr, sizeof(char), BUFFER_UNIT, tpl);
		total += read;
		tplStr = (char*)realloc(tplStr, total + BUFFER_UNIT);        // 1K 읽을 때 마다 1K 씩 메모리 증분
	}
	// 마지막에 Null character를 대입해 문자열 종료
	*(tplStr + total) = '\0';
	// Data File 읽기
	read, total = 0;
	while (feof(data) == 0)
	{
		read = fread(dataStr, sizeof(char), BUFFER_UNIT, data);
		total += read;
		dataStr = (char*)realloc(dataStr, total + BUFFER_UNIT);       // 1K 읽을 때 마다 1K 씩 메모리 증분
	}
	// 마지막에 Null character를 대입해 문자열 종료
	*(dataStr + total) = '\0';
	// Template과 Data를 병합하여 문법에 따라 결과 문서 생성. 결과는 render함수에 의해 renderedDocument에 저장됨.
	char* renderedDocument = (char*) 0;
	int resultStatus = render(tplStr, dataStr, &renderedDocument);
	// 오류발생
	if (resultStatus < 0) {
		printf("\nresult: %d", resultStatus);
	}
	else {
		// 결과 출력
		printf(renderedDocument);
	}

	// 메모리 해제
	if(renderedDocument != (char*) 0)
		free(renderedDocument);
	free(readBuf);
	free(tplStr);
	fclose(tpl);
	fclose(data);
}

void printUsage() {
	printf("Usage: <executable> template_file_path data_file_path\n");
}

int render(char* tplStr, char* dataStr, char** resultOut) {
	int result = -1; 

	char **dArr;
	dArr = (char **)malloc(sizeof(char *) * 25);
	*dArr = (char *)malloc(sizeof(char) * (25 * 50));
	for (int i = 1; i < 25; i++)
	{
		*(dArr + i) = *(dArr + i - 1) + 50;
	}      //datal의 "=" 뒷부분을 저장하는 2차원 array. 최대 25줄 저장 가능

	char **kArr;
	kArr = (char **)malloc(sizeof(char *) * 25);
	*kArr = (char *)malloc(sizeof(char) * (25 * 50));
	for (int i = 1; i < 25; i++)
	{
		*(kArr + i) = *(kArr + i - 1) + 50;
	}      //datal의 "=" 앞부분을 저장하는 2차원 array. 최대 25줄 저장 가능

	char **tArr;
	tArr = (char **)malloc(sizeof(char *) * 20);
	*tArr = (char *)malloc(sizeof(char) * (20 * 50));
	for (int i = 1; i < 20; i++)
	{
		*(tArr + i) = *(tArr + i - 1) + 50;
	}     //{}토큰 안쪽을 저장하는 2차원 array.

	int line_n = 0;     //tpl이나 datal에서 쪼개지는 줄 수  

	const char **tpll;
	tpll = (char **)malloc(sizeof(char *) * 10);
	*tpll = (char *)malloc(sizeof(char) * (10 * 100));
	for (int i = 1; i < 10; i++)
	{
		*(tpll + i) = *(tpll + i - 1) + 100;

	}                   //tpl 각각 쪼개지는 줄을 저장하는 2차원 array. 최대 10줄 저장 가능



	*(tpll + line_n) = strtok(tplStr, "\n");
	while (1)
	{

		if (*(tpll + line_n) == NULL)				 //종료조건
		{
			break;
		}
		line_n++;
		*(tpll + line_n) = strtok(NULL, "\n");
		//printf("%s \n", *(tpll + line_n));                    tpll 잘 나누어졌는지 확인
	}					//tpl을 나눠서 각각 line을 tpll[line_n]에 저장



	line_n = 0;         //line_n 재활용을 위해서 초기화
	int tArr_n = 0;     //line_n과 {}개수가 반드시 일치하는 것이 아니기때문에 새로 만든 정수
	int count = 2;
	while (1)
	{

		if (*(tpll + line_n) == NULL)                 //종료조건
		{
			break;
		}
		if (strstr(*(tpll + line_n), "{") == NULL)    //더이상 {토큰이 없을 때 다음줄로 넘어가기
		{
			line_n++;
		}
		else										  //뒤에 {토큰이 더 있을 때
		{
			tArr_n++;
			*(tArr + tArr_n) = strstr(*(tpll + line_n), "{");

			if (strstr(*(tArr + tArr_n) + 1, "{") == NULL) //뒤에 {토큰 1개로 끝
			{


				line_n++;
				count++;
			}
			else                                            //뒤에 {토큰 1개 이상일 때 while문으로 반복
			{
				while (1)
				{
					if (strstr(*(tArr + tArr_n) + 1, "{") == NULL)     //종료조건
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


	}                   //tArr[1] ~ tArr[count]까지 모든 {}값을 저장 해 놓음.※ 제대로 나눈것은 아니므로 함수에서 사용할때 잘 다듬어서 사용할것 ※
						/*
						for (int i = 1; i <= count; i++)
						{
						printf("%s \n", *(tArr + i));
						}
						*/                  //tArr 잘 나누어졌는지 확인

	char **datal;
	datal = (char **)malloc(sizeof(char *) * 25);
	*datal = (char *)malloc(sizeof(char) * (25 * 100));
	for (int i = 1; i < 25; i++)
	{
		*(datal + i) = *(datal + i - 1) + 100;
	}                   //data 각각 쪼개지는 줄을 저장하는 2차원 array. 최대 25줄 저장 가능



	line_n = 0;         //line_n 재활용을 위해서 초기화
	*(datal + line_n) = strtok(dataStr, "\n");
	while (1)
	{
		if (*(datal + line_n) == NULL)                //종료조건
		{
			break;
		}

		line_n++;
		*(datal + line_n) = strtok(NULL, "\n");

	}                 //data를 줄 별로 나눠서 각각 line을 datal[line_n]에 저장 


	line_n = 0;       //line_n 재활용을 위해서 초기화
	*(kArr + line_n) = strtok(*(datal + line_n), "=");
	dArr[line_n] = strtok(NULL, "=");
	while (1)
	{
		//printf("%s=%s \n", *(kArr + line_n), *(dArr + line_n));    kArr과 dArr잘 나누어졌는지 확인
		if (*(datal + line_n) == NULL)				  //종료조건
		{
			break;
		}

		line_n++;
		*(kArr + line_n) = strtok(*(datal + line_n), "=");
		*(dArr + line_n) = strtok(NULL, "=");


	}                           //data 속 "="의 뒤 값을 dArr에 저장, "key"앞부분을 kArr에 저장.



								//what_to_do(count, dArr, kArr, tArr, tpll, result);       //what_to_do 함수에서 find_func함수를 호출하면 이상하게 result와 temp가 같은 값이 되어서 돌아온다. 정상적인 진행 불가능


	find_func(0, *dArr, *kArr, *(tArr + 1), *tpll, resultOut);
	find_func(1, *(dArr + 1), *(kArr + 1), *(tArr + 2), *tpll, resultOut);
	printf("%s\n", *(resultOut));
	//beak에 대해서 딱 한 줄 정상적으로 되는 부분..

	free(datal);
	free(*datal);
	free(dArr);
	free(*dArr);
	free(kArr);
	free(*kArr);
	free(tArr);
	free(*tArr);
	free(tpll);
	free(*tpll);						//메인함수에서 사용한 동적할당 모두 free완료

	return 0;

	return result;
}

void find_func(int result_n, char *dArr, char *kArr, char *tArr, char *tpll, char **result)
//2차원이 아닌 array로 들어간다는 점을 주의. 이 함수에서 토큰을 만났을 때 어떤 행동을 취하는지 결정
{
	char *temp = (char *)malloc(sizeof(char) * 20);

	tArr = tArr + 1;                                        //덜 정리된 tArr부분을 정리해서 앞의 "{"를 잘라주는 과정.

	if (strncmp(tArr, "for", 3) == 0)                       //반복문
	{
		printf("for문\n");
	}
	else if (strncmp(tArr, "if", 2) == 0)	//if문, else문
	{
		printf("if문\n");
	}
	else if (strncmp(tArr, "@", 1) == 0)
	{
		printf("idx\n");
	}
	else if (strstr(tpll, "{") == NULL)     //단순 데이터 치환 특별한 경우(한 줄에 2개 연속 단순 데이터 치환)
	{
		*(result + result_n) = strcat(*(result + result_n - 1), dArr);
	}
	else									//단순 데이터 치환
	{
		temp = strtok(tpll, "{");
		*(result + result_n) = strtok(NULL, "{");
		temp = strcat(temp, dArr);
		*(result + result_n) = strcat(temp, *(result + result_n) + strlen(kArr) + 1);
	}										//위와 같은 방식으로하면 같은 line2개가 0과 1에 저장된다. 확인하고 print하게 하기

											//free(temp);                           //디버그 에러 왜 뜨는거야ㅓ랴앤ㅁ래ㅓㅔㅐ냥ㄹ
}

void what_to_do(int count, char **dArr, char **kArr, char **tArr, char **tpll, char **result)
{

	int t_num = 1;
	int k_num = 0;
	int d_num = 0;
	int line_n = 0;
	int result_n = 0;
	char *temp = (char *)malloc(sizeof(char) * 20);          //tpll저장용 array

	for (t_num; t_num <= count; t_num++)                     //t_num(t_Arr기준 정수)를 기준으로 실행돼는 반복문
	{
		if (strstr(*(tpll + line_n), "{") == NULL)           //tpl에서 {}이 하나도 없는 줄을 result에 그래로 넣어줌
		{
			*(result + result_n) = *(tpll + line_n);
			line_n++;
			result_n++;
		}
		else												//tpll에서 {}가 있는 부분. n개씩 있을 수도 있으니 주의
		{
			temp = *(tpll + line_n);
			find_func(result_n, *(dArr + d_num), *(kArr + k_num), *(tArr + t_num), *(tpll + line_n), *(result + result_n));
			*(result + result_n) = temp;
			strtok(*(tpll + line_n), "}");
			temp = strtok(NULL, "}");

			if (strstr(*(tpll + line_n), "{") == NULL)  //tpll에서 {}가 하나인 경우
			{
				temp = *(tpll + line_n);
				find_func(result_n, *(dArr + d_num), *(kArr + k_num), *(tArr + t_num), *(tpll + line_n), *(result + result_n)); //왜 그런지 모르겠지만 result값과 temp값(주소)이 같게 return 됀다ㅜㅜ 메인함수로 옮겨봐도 문제는 그대로 발생한다
				result_n++;
				d_num++;
				k_num++;
				t_num++;
				line_n++;
			}
			else										//tpll에서 {}가 하나이상인 경우
			{
				while (1)
				{
					temp = *(tpll + line_n);
					find_func(result_n, *(dArr + d_num), *(kArr + k_num), *(tArr + t_num), *(tpll + line_n), *(result + result_n));
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
