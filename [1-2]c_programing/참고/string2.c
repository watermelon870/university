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
	//문자열 -> 숫자
	num1 = atoi(s1); //stdlib.h에 포함 되는 atoi함수. 문자열 중 int부분을 반환해 준다. 실패시 return 0
	num2 = atof(s1); //stdlib.h에 포함 되는 atof함수. 문자열 중 double부분을 반환해 준다. 실패시 return 0;
	num3 = strtof(s1, NULL); //atoi의 float 버전, 다른점은 endptr을 적어 줘야 한다는 점이다.

	printf("%d//%lf//%f\n", num1, num2, num3);

	//숫자 -> 문자열
	char s2[20];			 //충분히 큰 크기로 배열을 선언 해 줘야 실행창에서 에러가 뜨지 않는다
	float num4 = 283.123;

	sprintf(s2, "%f", num4); //int의 경우 %d, 실수의 경우 %f로 바꿔주기만 하면 적용가능

	printf("%s\n", s2);

	return 0;
}