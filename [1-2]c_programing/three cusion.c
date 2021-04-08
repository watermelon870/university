#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>


#define PAUSE 112
#define ESC 27

#define MAP_ADJ_X 0
#define MAP_ADJ_Y 0
#define MAP_X 46
#define MAP_Y 23

int x[200], y[50]; //x,y 좌표값을 저장

int dir; //이동방향 저장 
int key; //입력받은 키 저장 

void gotoxy(int x, int y, char* s) { //x값을 2x로 변경, 좌표값에 바로 문자열을 입력할 수 있도록 printf함수 삽입  
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", s);
}

void title(void); //게임 시작화면 
void reset(void); //게임을 초기화 
void draw_map(void); // 게임판 테두리를 그림 
void game_over(void); //게임 오버를 확인 (미정)
void textcolor(int color_number) //콘솔창 출력색상을 나타내는 함수
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}


////////////////////////////MAIN START//////////////////////////////
int main() {


	system("mode con cols=184 lines=46");
	title();


}

///////////////////////////MAIN END////////////////////////////////
void title(void) {
	int i, j;

	while (_kbhit()) _getch(); //버퍼에 있는 키값을 버림 


	draw_map();    //맵 테두리를 그림 

	for (i = MAP_ADJ_Y + 1; i < MAP_ADJ_Y + MAP_Y - 1; i++) { // 맵 테두리 안쪽을 빈칸으로 채움 
		for (j = MAP_ADJ_X + 1; j < MAP_ADJ_X + MAP_X - 1; j++) gotoxy(j, i, "  ");
	}

	textcolor(15);
	system("Color 9f");//배경색

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 4, "+--------------------------+");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 5, "+--------------------------+");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 6, "     Three cushion          ");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 7, "+--------------------------+");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 8, "+--------------------------+");

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 9, " < PRESS ANY KEY TO START > ");

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 11, "   ◇↑,↓   : Angle    ");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 12, "   ◇ ←, → : Speed  ");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 13, "   ◇ R      : Reset             ");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 14, "   ◇ ESC    : Quit              ");



	while (1) {
		if (_kbhit()) { //키입력받음 
			key = _getch();
			if (key == ESC) exit(0); // ESC키면 종료 
			else break; //아니면 그냥 계속 진행 
		}
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 9, " < PRESS ANY KEY TO START > ");
		Sleep(400);
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 9, "                            ");
		Sleep(400);

	}
	reset(); // 게임을 초기화  
}

void reset(void) {

	system("cls"); //화면을 지움 
	draw_map(); //맵 테두리를 그림 
	while (_kbhit()) _getch(); //버퍼에 있는 키값을 버림 

}

void draw_map(void) { //맵 테두리 그리는 함수 
	int i;

	textcolor(15);//테두리 색
	system("Color 9f");//배경색
	for (i = 0; i < MAP_X; i++) {
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y, "■");
	}
	for (i = MAP_ADJ_Y + 1; i < MAP_ADJ_Y + MAP_Y - 1; i++) {
		gotoxy(MAP_ADJ_X, i, "■");
		gotoxy(MAP_ADJ_X + MAP_X - 1, i, "■");
	}
	for (i = 0; i < MAP_X; i++) {
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y + MAP_Y - 1, "■");
	}
}

void game_over(void) { //게임종료 함수 
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 6, MAP_ADJ_Y + 5, "+----------------------+");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 6, MAP_ADJ_Y + 6, "|      GAME OVER..     |");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 6, MAP_ADJ_Y + 7, "+----------------------+");

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 12, " Press any keys to restart.. ");


	Sleep(500);
	while (_kbhit()) _getch();
	key = _getch();
	title();
}
