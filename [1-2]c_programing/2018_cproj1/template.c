#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	/*
	구현영역
	*/
	return result;
}
