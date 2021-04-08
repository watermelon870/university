#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[20] = "Good day";   // string이 아닌 그냥 char 의 경우(str1[i]의 경우도 포함해서) '~'로 지정하는 반면 string은 "~~"로 지정
								 // 배열 선언 하면서 바로 문자열 리터럴을 할당해야 컴파일 에러가 발생하지 않는다!
	char* str1;                   
	str1 = (char *)malloc(sizeof(char) * 10);
	printf("str1 after malloc : ");
	scanf("%s", str1);
	printf("%s", str1);           //동적 할당을 진행 한 후면 받이들일 수 있다.
	//printf("%d \n", sizeof(str1));  -> 4출력
	
	/*
	str1 = "How are you";
	printf("str1 len : %d \n", strlen(str1)); 
								//그냥 str1 = "~~"선언 하지 않고 하면 이상한 값(1.5배)이 나오지만 "~~"선언 하고 나면 정상적으로 사용 가능.
	printf("str1 sizeof : %d \n", sizeof(str1));
								//sizeof(str1)은 여전히 포인터변수 이므로 4byte
	*/

	int count = 1;
	for (count; str1[count] != '\0'; count++)  //"\0"아닌거 조심
	{
		printf("%d ", count);
	}                           //count = 총 글자 개수 - 1

	printf("\n");

	printf("str sizeof :%d \nstr len : %d \n", sizeof(str), strlen(str)); //포인터변수가 아니므로 sizeof는 11, strlen은 실제 할당된 부분만 계산됨.

	int array[] = { 6,3,2,9,7,1,5,4,8 };
	const int length = sizeof(array) / sizeof(array[0]); //이런식으로 먼저 지정하지 않은 array의 length 측정 가능.

														 //char str1[11] = "Hello!";
														 //char str2[11];
														 //str2 = str1; -> 컴파일 에러뜸. 왜냐하면 단순히 배열의 시작 주소이며 변수가 아니다. 주소 값 대입 불가능

	printf("%s//%s\n", str, str + 3);     //string을 pointer처럼 사용가능하며 유연하게 바라 볼 수 있어야 한다

	//scanf("%10s", str);
	//printf("%s \n", str); //띄여쓰기 기준으로 인식 / %s 대신 %[^\n]s을 사용하면 공백까지 포함해서 입력받기 가능
	
	printf("str fgets : ");
	fgets(str, sizeof(str), stdin);					 // \n까지 입력받고 뒤에 \0가 추가로 저장됨 그래서 strlen쓰면 실제 크기보다 +1

	printf("%s \n", str);
	printf("str sizeof : %d \n", sizeof(str));
	printf("str len : %d \n", strlen(str));

	printf("str gets : ");
	gets(str);										 // \n이 \0으로 치환되어 저장된다. line의 길이가 str보다 길면 segfault발생하니 주의
	printf("%s \n", str);
	printf("str sizeof : %d \n", sizeof(str));
	printf("str len : %d \n", strlen(str));			 // 정적선언에서는 sizeof는 불변이고 strlen은 계속 바뀔 수 있다.

	//※포인터※에 문자열 리터럴(R-Value)을 사용한 경우(위에 주석처리된 "~~"부분)은 ☆읽기 전용이다!!!
	//반면에 정적할당으로 차지한 문자열 리터럴은 str[0] = 'i'; 이런 방법으로 집어 넣을 수 있다. 
	printf("str1 fgets: ");
	fgets(str1, 20, stdin);                      // int값은 sizeof(char)나 20이나 뭘 넣어도 상관 없음, 다만 ★위에서 주석처리한 str1을 "~~"로  선언한 부분이 있어서 못 가져온듯
	printf("%s \n", str1);
	printf("str1 sizeof : %d \n", sizeof(str1));
	printf("str1 len : %d \n", strlen(str1));	


	//string.h 함수 목록

	strlen(str);								// 길이를 계산.
	strcpy(str, str1), strncpy(str, str1, 10);	// 뒤에거를 앞에거에 복사.
	strcmp(str, str1), strncmp(str, str1, 10);	// 둘이 비교해서 +, 0, -값 출력.
	strcat(str, str1), strcat(str, str1, 10);	// 뒤에거를 앞에거에 붙이기.
	sscanf, sprintf;							// 메모리 속 것들을 가져와서 행동
	strstr(str, str1);							// 앞에서 뒤에 부분을 찾아서 해당 주소 가져오기.
	strchr(str, 'h');                           // 문자열에서 검색할 문자 선택. 선택 문자부터의 주소값 retrun
	strrchr(str, 'h');                          // 문자열 오른쪽(r)부터 문자 검색 시작
	strtok(str, " ");                           // 뒤를 기준으로 앞 문자열을 잘라서 return
	//strtok(NULL, " "); 이렇게 사용 해 줄 수 있는데 이건 앞에서 자르고 남은 뒤 부분을 의미한다

	/*★★0xC0000005: 0x013A585D 위치를 기록하는 동안 액세스 위반이 발생했습니다. -> 이 에러는 읽기 전용 상태 일 때 발생한다.
	즉, 문자열 리터럴을 할당하는 대신 동적 메모리를 할당하고 문자열을 복사하면 이 문제를 해결 할 수 있다!!*/

	free(str1);

	return 0;
}