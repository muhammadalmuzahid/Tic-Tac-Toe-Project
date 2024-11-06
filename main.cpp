#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string.h>

using namespace std;

long int XP,YP, H, W;
int x1, x2, x3, x4, Y1, y2, y3, y4;
char arr[30]="AI - TicTacToe";
int pointX[10];
int pointY[10];
char Board[10];
char name[20];
char Ai[20] = "Computer";
int cWins = 0, pWins = 0;

void set_mainScreen1() {
	setcolor(WHITE);
	cleardevice();
	setbkcolor(CYAN);
	setfillstyle(XHATCH_FILL, BLACK);
	bar(0,0,XP,YP);
	setfillstyle(SOLID_FILL,BLUE);
	bar(30,30,XP-30,YP-60);

	/// Title name of Game
	setbkcolor(BLUE);
	string welcome = "WELCOME TO";
	settextstyle(BOLD_FONT, 0, 6);
	setcolor(WHITE);
	char temp[20] = ""; char tempp[2] = "";	Sleep(300);
	for (int i = 0; i < 10; i++){
		tempp[0] = welcome[i]; 		strcat(temp, tempp);
		outtextxy((XP - textwidth(temp))/2 -10, YP*0.09, temp);	Sleep(50);
	}

	Sleep(100);
	string gnome = "TIC TAC TOE";
	settextstyle(BOLD_FONT, 0, 10);
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < gnome.length(); i++){
		tempp[0] = gnome[i]; 	strcat(temp, tempp);
		outtextxy((XP - textwidth(temp))/2 -10, YP*0.15, temp);	Sleep(70);
	}

	Sleep(100);
	string copyright = "by Muzahid";
	settextstyle(BOLD_FONT, 0, 5);
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < copyright.length(); i++){
		tempp[0] = copyright[i]; 	strcat(temp, tempp);
		outtextxy(XP*0.73, YP*0.29, temp);	Sleep(50);
	}


	setlinestyle(DASHED_LINE, 0, 10);
	line(XP/10, YP*0.35, XP-XP/10, YP*0.35);
	Sleep(200);
}

void displayOptions(string arr1, char arr2[], char arr3[]){
	settextstyle(BOLD_FONT, 0, 4);
	char temp[50] = ""; char tempp[2] = "";
	for (int i = 0; i < arr1.length(); i++){
		tempp[0] = arr1[i]; 	strcat(temp, tempp);
		outtextxy((XP -textwidth(temp) -2)/2, (YP -30)*0.6, temp);		Sleep(30);
	}

	Sleep(100);
	rectangle(XP *0.46 -160, YP*0.65, XP*0.46, YP*0.65 +50);
	rectangle(XP*0.54, YP*0.65, XP*0.54 +160, YP*0.65 +50);

	setcolor(LIGHTGRAY);
	settextstyle(SANS_SERIF_FONT,0,2);
	outtextxy(XP*0.46 -113, YP*0.65 +13, arr2);
	outtextxy(XP*0.54 +30, YP*0.65 +13, arr3);
}

void restart_button() {
	setlinestyle(0,0,4);
	setcolor(LIGHTCYAN);
	setlinestyle(SOLID_LINE,0,5);
	char arr[10]="RESTART"; char arrr[10] = "EXIT";
	rectangle(XP*0.65, YP*0.75, XP*0.67 +90, YP*0.75 +40);
	rectangle(XP*0.68 +100, YP*0.75, XP*0.7 +190, YP*0.75 +40);
	setlinestyle(SOLID_LINE,0,1);
	setbkcolor(BLUE);
	settextstyle(SANS_SERIF_FONT,0,3);
	outtextxy(XP*0.66, YP*0.75 +9, arr);
	outtextxy(XP*0.69 +120, YP*0.75 +9, arrr);
	setbkcolor(BLACK);
}

void highlight_button(int x,int y, int cl) {
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	floodfill(x,y,cl);
}


int choice_input1()
{
	POINT cursor;
	int xp,yp;
	while(1)
	{
		GetCursorPos(&cursor);
		xp=cursor.x;
		yp=cursor.y;
		if(GetAsyncKeyState(VK_LBUTTON) && (xp>XP*0.46-160 && xp<XP*0.46) && (yp>YP*0.69 && yp<YP*0.69+50)) {
			highlight_button(XP*0.46-150, YP*0.69 +10, WHITE);
			return 1;
			break;
		}
		if(GetAsyncKeyState(VK_LBUTTON) && (xp>XP*0.54 && xp<XP*0.54 +160) && (yp>XP*0.54 && yp<YP*0.72+50)) {
			highlight_button(XP*0.54 +10, XP*0.54 +10, WHITE);
			return 2;
			break;
		}
		Sleep(1);
	}
}

int choice_input2()	{
	POINT cursor;
	int xp,yp;
	while(1)
	{
		GetCursorPos(&cursor);
		xp=cursor.x;
		yp=cursor.y;
		if(GetAsyncKeyState(VK_LBUTTON) && (xp>XP*0.65 && xp<XP*0.67 +90) && (yp>YP*0.79 && yp<YP*0.79 +40)) {
			highlight_button(XP*0.65 +5, YP*0.79 +5, LIGHTCYAN);
			return 1;
			break;
		}
		if(GetAsyncKeyState(VK_LBUTTON) && (xp>XP*0.68 +100 && xp<XP*0.7 +190) && (yp>YP*0.79 && yp<YP*0.79 +40)) {
			highlight_button(XP*0.68 +105, YP*0.79 +5, LIGHTCYAN);
			return 2;
			break;
		}
		Sleep(1);
	}
}

void setName(){
	setcolor(WHITE);
	settextstyle(BOLD_FONT, 0, 4);
	outtextxy(XP*0.11, YP*0.4, "Enter your name:");
	for (int i = 0; i < 16; i++){
		char c = getch();
		if (c == 13) break;
		char str[2];
	    sprintf(str, "%c", c);
	    strcat(name, str);
		outtextxy(XP*0.2, YP*0.46, name);
	}
}

void displayGameInfo(char L){
	setcolor(WHITE);
	setbkcolor(BLUE);
	settextstyle(BOLD_FONT, 0, 4);
	char turn[30] = "";
	if (L == 'P'){
		strcat(turn, name);
		strcat(turn, "'s turn");
	}
	else if (L == 'C'){
		strcat(turn, Ai);
		strcat(turn, "'s turn");
	}
	outtextxy(XP*0.6, YP*0.3, turn);
}
void Wins(){
	char turn[30] = "";
	setcolor(WHITE);
	setbkcolor(BLUE);
	settextstyle(BOLD_FONT, 0, 4);
	sprintf(turn, "Computer Won: %d", cWins);
	outtextxy(XP*0.6, YP*0.45, turn);
	sprintf(turn, "%s Won: %d", name, pWins);
	outtextxy(XP*0.6, YP*0.5, turn);
}

void set_mainScreen2(){
	cleardevice();
	setbkcolor(CYAN);
	setfillstyle(XHATCH_FILL, BLACK);
	bar(0,0,XP,YP);
	setfillstyle(SOLID_FILL,BLUE);
	bar(30,30,XP-30,YP-40);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, 4);
	line(x1, Y1, x2, Y1);
	line(x1, y2, x2, y2);
	line(x3, y3, x3, y4);
	line(x4, y3, x4, y4);

	setlinestyle(SOLID_LINE, 0, 10);
	line(XP*0.55, YP*0.15, XP*0.55, YP*0.85);
}

void drawCross(int x, int y, int r){
	setcolor(LIGHTRED);
	setlinestyle(SOLID_LINE, 0, 8);
	line(x-r, y-r, x+r, y+r);
	line(x-r, y+r, x+r, y-r);
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, 4);
	line(x-r, y-r, x+r, y+r);
	line(x-r, y+r, x+r, y-r);
	setcolor(WHITE);
}

void drawCircle(int x, int y, int r){
	setcolor(LIGHTCYAN);
	setlinestyle(SOLID_LINE, 0, 8);
	circle(x, y, r);
	setcolor(CYAN);
	setlinestyle(SOLID_LINE, 0, 4);
	circle(x, y, r);
	setcolor(WHITE);
}

void Loading(){
	XP = GetSystemMetrics(SM_CXSCREEN);
	YP = GetSystemMetrics(SM_CYSCREEN) - 10;H = YP * 0.5;
	initwindow(XP,YP,arr);
	for (int i = 0; i < 10; i++){
		Board[i] = ' ';
	}
	x1 = XP*0.15; x2 = XP*0.15 + H; Y1 = YP*0.22 + H*0.32; y2 = YP*0.22 + H*0.68;
	x3 = XP*0.15 + H*0.32; x4 = XP*0.15 + H*0.68; y3 = YP*0.22; y4 = YP*0.22 + H;

	pointX[1] = (x3-x1)/2 +x1;
	pointX[4] = pointX[1]; pointX[7] = pointX[1];
	pointX[2] = (x4-x3)/2 +x3;
	pointX[5] = pointX[2]; pointX[8] = pointX[2];
	pointX[3] = (x2-x4)/2 +x4;
	pointX[6] = pointX[3]; pointX[9] = pointX[3];

	pointY[1] = (y4-y2)/2 +y2;
	pointY[2] = pointY[1]; pointY[3] = pointY[1];
	pointY[4] = (y2-Y1)/2 +Y1;
	pointY[5] = pointY[4]; pointY[6] = pointY[4];
	pointY[7] = (Y1-y3)/2 +y3;
	pointY[8] = pointY[7]; pointY[9] = pointY[7];
}

void drawMoves(){
	for (int i = 1; i < 10; i++){
		if (Board[i] == 'O'){
			drawCircle(pointX[i], pointY[i], 30);
		}
		else if (Board[i] == 'X'){
			drawCross(pointX[i], pointY[i], 30);
		}
	}
}

int getnum(){
	POINT cursor;
	int xp,yp;
	while(true)
	{
		GetCursorPos(&cursor);
		xp=cursor.x;
		yp=cursor.y;
		if(GetAsyncKeyState(VK_LBUTTON) && (xp>x1+5 && xp<x3-5) && (yp>y2+30 && yp<y4+20)) {
			return 1;
			break;
		}
		if(GetAsyncKeyState(VK_LBUTTON) && (xp>x3+5 && xp<x4-5) && (yp>y2+30 && yp<y4+20)) {
			return 2;
			break;
		}
		if(GetAsyncKeyState(VK_LBUTTON) && (xp>x4+5 && xp<x2-5) && (yp>y2+30 && yp<y4+20)) {
			return 3;
			break;
		}
		if(GetAsyncKeyState(VK_LBUTTON) && (xp>x1+5 && xp<x3-5) && (yp>Y1+30 && yp<y2+20)) {
			return 4;
			break;
		}
		if(GetAsyncKeyState(VK_LBUTTON) && (xp>x3+5 && xp<x4-5) && (yp>Y1+30 && yp<y2+20)) {
			return 5;
			break;
		}
		if(GetAsyncKeyState(VK_LBUTTON) && (xp>x4+5 && xp<x2-5) && (yp>Y1+30 && yp<y2+20)) {
			return 6;
			break;
		}
		if(GetAsyncKeyState(VK_LBUTTON) && (xp>x1+5 && xp<x3-5) && (yp>y3+30 && yp<Y1+20)) {
			return 7;
			break;
		}
		if(GetAsyncKeyState(VK_LBUTTON) && (xp>x3+5 && xp<x4-5) && (yp>y3+30 && yp<Y1+20)) {
			return 8;
			break;
		}
		if(GetAsyncKeyState(VK_LBUTTON) && (xp>x4+5 && xp<x2-5) && (yp>y3+30 && yp<Y1+20)) {
			return 9;
			break;
		}
		Sleep(1);
	}
}

int playerMove(){
	settextstyle(BOLD_FONT,0,3);
	setcolor(WHITE); setbkcolor(BLUE);
	char chose[30] = "TIC TAC TOE";
	outtextxy(XP*0.6, YP*0.2, chose);
	int move = getnum();
	while (true){
		if (Board[move] == ' '){
			return move;
		}
		else{
			setbkcolor(BLUE);
			settextstyle(BOLD_FONT,0,3);
			setcolor(LIGHTRED);
			char error[30] = "Invalid Move! Enter again";
			outtextxy(XP*0.6, YP*0.7, error);
			move = getnum();
		}
	}
}

int Winner(char Board[], char l){
	if (Board[7] == l && Board[8] == l && Board[9] == l){
		return 3;
	}
	else if (Board[4] == l && Board[5] == l && Board[6] == l){
		return 2;
	}
	else if (Board[1] == l && Board[2] == l && Board[3] == l){
		return 1;
	}
	else if (Board[7] == l && Board[4] == l && Board[1] == l){
		return 4;
	}
	else if (Board[2] == l && Board[8] == l && Board[5] == l){
		return 5;
	}
	else if (Board[3] == l && Board[6] == l && Board[9] == l){
		return 6;
	}
	else if (Board[1] == l && Board[5] == l && Board[9] == l){
		return 8;
	}
	else if (Board[7] == l && Board[5] == l && Board[3] == l){
		return 7;
	}
	return 0;
}

bool emptyB(){
	for (int i = 1; i < 10; i++){
		if (Board[i] == ' '){
			return false;
		}
	}
	return true;
}

int randAImove(int amv[]){
	srand(time(0));
	int ai[4];
	int AI = 0;
	for (int i = 1; i < 10; i++){
		for (int j = 0; j < 4; j++){
			if (amv[j] == i){
				if (Board[i] == ' '){
					ai[AI] = i;
					AI++;
				}
			}
		}
	}

	if (AI == 0){
		return AI;
	}

	int k = rand() % AI;
	return ai[k];
}

int AI(char cl, char pl){
	settextstyle(BOLD_FONT,0,3);
	setcolor(WHITE); setbkcolor(BLUE);
	char chose[30] = "TIC TAC TOE";
	outtextxy(XP*0.6, YP*0.2, chose);
	char duplex[10];

	for (int i = 1; i < 10; i++){
		if (Board[i] == ' '){
			for (int j = 0; j < 10; j++){
				duplex[j] = Board[j];
			}
			duplex[i] = cl;
			if (Winner(duplex, cl) != 0){
				return i;
			}
		}
	}

	for (int i = 1; i < 10; i++){
		if (Board[i] == ' '){
			for (int j = 0; j < 10; j++){
				duplex[j] = Board[j];
			}
			duplex[i] = pl;
			if (Winner(duplex, pl) != 0){
				return i;
			}
		}
	}

	int ai[4] = {1, 3, 7, 9};
	int move = randAImove(ai);
	if (move != 0){
		return move;
	}

	if (Board[5] == ' '){
		return 5;
	}

	int AI[4] = {1, 4, 6, 8};
	move = randAImove(AI);
	return move;
}

char First(){
	srand(time(0));
	int ai = rand() % 2;
	setbkcolor(BLUE);
	settextstyle(BOLD_FONT,0,4);
	setcolor(LIGHTRED);
	if (ai == 0){
		char err[60] = "Computer's turn";
		outtextxy((XP -textwidth(err) -2) /3, YP*0.8, err);

		Sleep(700);
		return 'C';
	}
	else {
		char err[50] = ""; strcat(err, name); strcat(err, "'s turn");
		outtextxy((XP -textwidth(err) -2) /3, YP*0.8, err);

		Sleep(700);
		return 'P';
	}
}

void DrawWinLine(int n){
	setlinestyle(SOLID_LINE, 0, 8);
	setcolor(CYAN);
	switch(n){
	case 1:
		line(pointX[1] -20, pointY[1], pointX[3] +20, pointY[3]);
		setlinestyle(SOLID_LINE, 0, 4);
		setcolor(WHITE);
		line(pointX[1] -20, pointY[1], pointX[3]+20, pointY[3]);
		break;
	case 2:
		line(pointX[4] -20, pointY[4], pointX[6]+20, pointY[6]);
		setlinestyle(SOLID_LINE, 0, 4);
		setcolor(WHITE);
		line(pointX[4] -20, pointY[4], pointX[6]+20, pointY[6]);
		break;
	case 3:
		line(pointX[7]-20, pointY[7], pointX[9]+20, pointY[9]);
		setlinestyle(SOLID_LINE, 0, 4);
		setcolor(WHITE);
		line(pointX[7] -20, pointY[7], pointX[9]+20, pointY[9]);
		break;
	case 4:
		line(pointX[7], pointY[7]-20, pointX[1], pointY[1]+20);
		setlinestyle(SOLID_LINE, 0, 4);
		setcolor(WHITE);
		line(pointX[7], pointY[7]-20, pointX[1], pointY[1]+20);
		break;
	case 5:
		line(pointX[8], pointY[8]-20, pointX[2], pointY[2]+20);
		setlinestyle(SOLID_LINE, 0, 4);
		setcolor(WHITE);
		line(pointX[8], pointY[8]-20, pointX[2], pointY[2]+20);
		break;
	case 6:
		line(pointX[9], pointY[9]-20, pointX[3], pointY[3]+20);
		setlinestyle(SOLID_LINE, 0, 4);
		setcolor(WHITE);
		line(pointX[9], pointY[9]-20, pointX[3], pointY[3]+20);
		break;
	case 7:
		line(pointX[7] -25, pointY[7] -20, pointX[3]+15, pointY[3]+20);
		setlinestyle(SOLID_LINE, 0, 4);
		setcolor(WHITE);
		line(pointX[7]-25, pointY[7]-20, pointX[3]+15, pointY[3]+20);
		break;
	case 8:
		line(pointX[1]-15, pointY[1]+20, pointX[9]+25, pointY[9]-20);
		setlinestyle(SOLID_LINE, 0, 4);
		setcolor(WHITE);
		line(pointX[1]-15, pointY[1]+20, pointX[9]+25, pointY[9]-20);
		break;
	}
}

int main(){
	Loading();
	char arr1[20]="Select Game Mode";
	char arr6[40]="Do you want to play as X or O?";
	char arr2[30] = "FRIEND";
	char arr3[30] = "COMPUTER";
	char arr4[20] = "     X";
	char arr5[20] = "        O";
	char pl, cl;

	set_mainScreen1();
	setName();
	displayOptions(arr6, arr4, arr5);
	int x = choice_input1();
	if (x == 1){ pl = 'X'; cl = 'O';  }
	else{ pl = 'O'; cl = 'X';  }
	char turn = First();
	int move = 0;
	bool OPGamePlay = true;
	while (true){
		srand(time(0));
		if (turn == 'P'){
			set_mainScreen2();
			drawMoves();
			displayGameInfo(turn);
			Wins();
			move = playerMove();
			Board[move] = pl;
			int winC = Winner(Board, pl);
			if (winC != 0){
				pWins++;
				set_mainScreen2();
				drawMoves();
				DrawWinLine(winC);
				char win[20] = "";	setbkcolor(BLUE);
				strcat(win, name); strcat(win, " Won");
				settextstyle(BOLD_FONT,0,5);
				setcolor(GREEN);
				outtextxy(XP*0.6, YP*0.3, win);
				OPGamePlay = false;
			}
			else if(emptyB()){
				set_mainScreen2();
				drawMoves();
				char win[20] = "Game Tied ";
				settextstyle(BOLD_FONT,0,5);
				setcolor(LIGHTRED); setbkcolor(BLUE);
				outtextxy(XP*0.6, YP*0.3, win);
				OPGamePlay = false;
			}
			else turn = 'C';

		}
		else{
			set_mainScreen2();
			drawMoves();
			displayGameInfo(turn);	Wins();
			move = AI(cl, pl);
			Sleep(1);

			Board[move] = cl;
			int winC = Winner(Board, cl);
			if (winC != 0){
				cWins++;
				set_mainScreen2();
				drawMoves();
				DrawWinLine(winC);
				setbkcolor(BLUE);
				char win[20] = "Computer Wins!";
				settextstyle(BOLD_FONT,0,5);
				setcolor(LIGHTRED); setbkcolor(BLUE);
				outtextxy(XP*0.6, YP*0.3, win);
				OPGamePlay = false;
			}
			else if(emptyB()){
				set_mainScreen2();
				drawMoves();
				char win[20] = "Game Tied ";
				settextstyle(BOLD_FONT,0,5);
				setcolor(LIGHTRED); setbkcolor(BLUE);
				outtextxy(XP*0.6, YP*0.3, win);
				OPGamePlay = false;
			}
			else turn = 'P';
		}
		if (!OPGamePlay) {
			Wins();
			restart_button();
			if (choice_input2() == 1){
				OPGamePlay = true;
				for (int i = 0; i < 10; i++){
					Board[i] = ' ';
				}
				turn = First();
				move = 0;
			}
			else{
				break;
			}
		}
	}
	Sleep(500);
	closegraph();
	return 0;
}
