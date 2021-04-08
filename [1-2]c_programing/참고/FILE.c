#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//파일에 문자열 쓰기 - fprintf
	FILE *fp;
	fp = fopen("hello.txt", "w");				 // hello.txt 파일을 쓰기모드(w)로 열기 

	fprintf(fp, "%s %d\n%d", "Hello", 100, 200); //서식("%s %d\n")을 지정하여 문자열을 파일에 저장

	fclose(fp);									 //일종의 동적 메모리 할당이라서 free같이 포인터를 닫아야한다.

	//파일에서 문자열 읽기 - fscanf
	char s1[10];
	int num1;
	int num2;

	FILE *fp1 = fopen("hello.txt", "r");			 //hello.txt 파일을 읽기모드(r)로 열기

	fscanf(fp1, "%s %d %d", s1, &num1, &num2);

	printf("%s %d %d \n", s1, num1, num2);

	fclose(fp1);

	//파일에 문자열 쓰기 - fputs
	FILE* fp2 = fopen("hello.txt", "w");

	fputs("Hello, World!", fp2);					//서식을 정해주지 않고서 사용 할 수 있는 편리함

	fclose(fp2);

	//파일에서 문자열 쓰기 - fwrite
	FILE *fp3 = fopen("hello.txt", "w");

	fwrite(s1, strlen(s1), 1, fp3);					// fwrite(문자열, 쓰기 크기, 쓰기 횟수, 파일포인터)

	fclose(fp3);

	//파일에서 문자열 가져오기 - fgets
	char buffer[20];                                // 넘어가도 그냥 안 받는 정도로 끝나고 컴파일 에러가 나오지는 않는다

	FILE *fp4 = fopen("hello.txt", "r");            // 나누는 기준이 \n이므로 주의하자

	fgets(buffer, sizeof(buffer), fp4);

	fputs(buffer, stdout);

	fclose(fp4);

	//파일에서 문자열 가져오기 - fread은 너굴맨이 처리했으니 안심하라구

	return 0;
}