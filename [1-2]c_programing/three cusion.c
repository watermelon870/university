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

int x[200], y[50]; //x,y ��ǥ���� ����

int dir; //�̵����� ���� 
int key; //�Է¹��� Ű ���� 

void gotoxy(int x, int y, char* s) { //x���� 2x�� ����, ��ǥ���� �ٷ� ���ڿ��� �Է��� �� �ֵ��� printf�Լ� ����  
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", s);
}

void title(void); //���� ����ȭ�� 
void reset(void); //������ �ʱ�ȭ 
void draw_map(void); // ������ �׵θ��� �׸� 
void game_over(void); //���� ������ Ȯ�� (����)
void textcolor(int color_number) //�ܼ�â ��»����� ��Ÿ���� �Լ�
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

	while (_kbhit()) _getch(); //���ۿ� �ִ� Ű���� ���� 


	draw_map();    //�� �׵θ��� �׸� 

	for (i = MAP_ADJ_Y + 1; i < MAP_ADJ_Y + MAP_Y - 1; i++) { // �� �׵θ� ������ ��ĭ���� ä�� 
		for (j = MAP_ADJ_X + 1; j < MAP_ADJ_X + MAP_X - 1; j++) gotoxy(j, i, "  ");
	}

	textcolor(15);
	system("Color 9f");//����

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 4, "+--------------------------+");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 5, "+--------------------------+");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 6, "     Three cushion          ");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 7, "+--------------------------+");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 8, "+--------------------------+");

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 9, " < PRESS ANY KEY TO START > ");

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 11, "   �ޡ�,��   : Angle    ");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 12, "   �� ��, �� : Speed  ");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 13, "   �� R      : Reset             ");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 14, "   �� ESC    : Quit              ");



	while (1) {
		if (_kbhit()) { //Ű�Է¹��� 
			key = _getch();
			if (key == ESC) exit(0); // ESCŰ�� ���� 
			else break; //�ƴϸ� �׳� ��� ���� 
		}
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 9, " < PRESS ANY KEY TO START > ");
		Sleep(400);
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 9, "                            ");
		Sleep(400);

	}
	reset(); // ������ �ʱ�ȭ  
}

void reset(void) {

	system("cls"); //ȭ���� ���� 
	draw_map(); //�� �׵θ��� �׸� 
	while (_kbhit()) _getch(); //���ۿ� �ִ� Ű���� ���� 

}

void draw_map(void) { //�� �׵θ� �׸��� �Լ� 
	int i;

	textcolor(15);//�׵θ� ��
	system("Color 9f");//����
	for (i = 0; i < MAP_X; i++) {
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y, "��");
	}
	for (i = MAP_ADJ_Y + 1; i < MAP_ADJ_Y + MAP_Y - 1; i++) {
		gotoxy(MAP_ADJ_X, i, "��");
		gotoxy(MAP_ADJ_X + MAP_X - 1, i, "��");
	}
	for (i = 0; i < MAP_X; i++) {
		gotoxy(MAP_ADJ_X + i, MAP_ADJ_Y + MAP_Y - 1, "��");
	}
}

void game_over(void) { //�������� �Լ� 
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 6, MAP_ADJ_Y + 5, "+----------------------+");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 6, MAP_ADJ_Y + 6, "|      GAME OVER..     |");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 6, MAP_ADJ_Y + 7, "+----------------------+");

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 12, " Press any keys to restart.. ");


	Sleep(500);
	while (_kbhit()) _getch();
	key = _getch();
	title();
}
