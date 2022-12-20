#include "graphics.h"
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <math.h>
#include <string>

using namespace std;

const int Otypetext1x = 100;
const int Otypetext1y = 0;

const int Otypetext2x = 500;
const int Otypetext2y = 0;

const int Otypenumberx = 100;
const int Otypenumbery = 415;

const int Otyperectx = 100;
const int Otyperecty = 950;

struct Record {
	char Data;
	int Key;
};

void text() {
	setfontcolor(2);

	outtextxy(10 + Otypetext1x, Otypetext1y + 10, "for (int i = 1; i <= N; i++) Count[i] = 0;");
	outtextxy(10 + Otypetext1x, Otypetext1y + 20, "for (int i = N; i >= 2; --i) {");

	outtextxy(40 + Otypetext1x, Otypetext1y + 50, "for (int j = i - 1; j >= 1; --j) {");

	outtextxy(70 + Otypetext1x, Otypetext1y + 80, "if (R[i].Key < R[j].Key) Count[j]++;");
	outtextxy(70 + Otypetext1x, Otypetext1y + 90, "else Count[i]++;");
	outtextxy(40 + Otypetext1x, Otypetext1y + 100, "}");
	outtextxy(10 + Otypetext1x, Otypetext1y + 110, "}");

	outtextxy(10 + Otypetext1x, Otypetext1y + 140, "for (int i = 1; i <= N; ++i)");
	outtextxy(40 + Otypetext1x, Otypetext1y + 150, "RR[Count[i] + 1] = R[i];");

	setfontcolor(4);
}

void drawstep(Record R[], int Count[], int i, int j, int stepth) {
	if (stepth >= 1) {
		if (stepth == 1) setfontcolor(9);
		outtextxy(Otypetext2x + 10, Otypetext2y + 20, "i = " + to_string(i));
		setfontcolor(4);
	}
	if (stepth >= 2) {
		if (stepth == 2) setfontcolor(9);
		outtextxy(40 + Otypetext2x, Otypetext2y + 50, "j = " + to_string(j));
		setfontcolor(4);
	}
	if (stepth == 3) {
		setfontcolor(9);
		outtextxy(70 + Otypetext2x, Otypetext2y + 80, "Kiem tra (" + to_string(R[i].Key) + " < " + to_string(R[j].Key) + ")");
		outtextxy(100 + Otypetext2x, Otypetext2y + 90, "Dung Count[" + to_string(j) + "]++");
		setfontcolor(4);
	}
	if (stepth == 4) {
		setfontcolor(9);
		outtextxy(70 + Otypetext2x, Otypetext2y + 80, "Kiem tra (" + to_string(R[i].Key) + " < " + to_string(R[j].Key) + ")");
		outtextxy(100 + Otypetext2x, Otypetext2y + 90, "Sai Count[" + to_string(i) + "]++");
		setfontcolor(4);
	}
	Sleep(500);
}

void drawstep2(int i, int Count[]) {
	setfontcolor(9);
	outtextxy(10 + Otypetext2x, Otypetext2y + 140, "i = " + to_string(i));
	outtextxy(40 + Otypetext2x, Otypetext2y + 150, "RR[" + to_string(Count[i] + 1) + "] = R[" + to_string(i) + "];");
	setfontcolor(9);
}

void draw0(Record R[], int N, int idx, int j) {
	setcolor(4), setfontcolor(4);
	for (int i = 1; i <= N; ++i)
	{
		if (i == j)
		{
			rectangle(Otyperectx + 61 * i, Otyperecty - 15 * R[idx].Key,
				Otyperectx + 50 + 61 * i, Otyperecty);
		}
	}
	Sleep(1500);
}

void draw(Record R[], int Count[], int N, int j, int k) {
	setcolor(4), setfontcolor(4);

	outtextxy(Otypenumberx - 81, Otypenumbery - 20, "Index");
	outtextxy(Otypenumberx - 81, Otypenumbery - 10, "Count[Index]");
	outtextxy(Otypenumberx - 81, Otypenumbery, "RR[Index].Key");

	for (int i = 1; i <= N; ++i) {
		if (i == k || i == j) setcolor(9), setfontcolor(9);

		outnumberxy(Otypenumberx + 54 * i, Otypenumbery - 20, i);
		outnumberxy(Otypenumberx + 54 * i, Otypenumbery - 10, Count[i]);
		outnumberxy(Otypenumberx + 54 * i, Otypenumbery, R[i].Key);

		rectangle(Otyperectx + 61 * i, Otyperecty - 15 * R[i].Key,
			Otyperectx + 50 + 61 * i, Otyperecty);

		setcolor(4), setfontcolor(4);
	}
}

void draw2(Record R[], int Count[], int N, int j, int k) {
	system("cls");
	text();
	draw(R, Count, N, j, k);
	Sleep(50);
	draw(R, Count, N, j, k);
	Sleep(50);
}

void ComparisonSort(Record R[], int N) {
	int Count[100];
	for (int i = 1; i <= N; i++) Count[i] = 0;

	draw2(R, Count, N, -1, -1);

	for (int i = N; i >= 2; --i) {
		drawstep(R, Count, i, -1, 1);
		for (int j = i - 1; j >= 1; --j) {
			drawstep(R, Count, i, j, 2);
			if (R[i].Key < R[j].Key) {
				draw2(R, Count, N, i, j);
				Count[j]++;
				draw2(R, Count, N, i, j);
				drawstep(R, Count, i, j, 3);
			}
			else {
				draw2(R, Count, N, i, j);
				Count[i]++;
				draw2(R, Count, N, i, j);
				drawstep(R, Count, i, j, 4);
			}
		}
	}

	draw2(R, Count, N, -1, -1);
	system("cls");

	text();
	outtextxy(Otypenumberx - 81, Otypenumbery - 20, "Index");
	outtextxy(Otypenumberx - 81, Otypenumbery - 10, "Count[Index]");
	outtextxy(Otypenumberx - 81, Otypenumbery, "R[Index].Key");
	for (int i = 1; i <= N; ++i)
		outnumberxy(Otypenumberx + 54 * i, Otypenumbery - 20, i);

	for (int i = 1; i <= N; ++i) {
		outnumberxy(Otypenumberx + 54 * i, Otypenumbery - 10, Count[i]);
		outnumberxy(Otypenumberx + 54 * (Count[i] + 1), Otypenumbery, R[i].Key);
		draw0(R, N, i, Count[i] + 1);
		drawstep2(i, Count);
	}
}

int main() {
	initgraph();
	DisableSelection();
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	/*
	int N = 16;
	Record R[100];

	R[1].Key = 2;
	R[2].Key = 3;
	R[3].Key = 7;
	R[4].Key = 8;
	R[5].Key = 10;
	R[6].Key = 5;
	R[7].Key = 4;
	R[8].Key = 1;
	R[9].Key = 9;
	R[10].Key = 3;
	R[11].Key = 6;
	R[12].Key = 8;
	R[13].Key = 10;
	R[14].Key = 13;
	R[15].Key = 2;
	R[16].Key = 4;
	*/

	cout << "Nhap vao so luong phan tu: ";
	int N; cin >> N;
	Record R[100];
	cout << "Nhap vao gia tri cac phan tu: ";
	for (int i = 1; i <= N; ++i) cin >> R[i].Key;

	ComparisonSort(R, N);

	_getch();
	system("cls");
	return 0;
}