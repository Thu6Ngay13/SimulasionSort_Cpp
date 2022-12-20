#include "graphics.h"
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <math.h>
#include <string>

using namespace std;

const int Otypetext1x = 100;
const int Otypetext1y = 0;

const int Otypetext2x = 700;
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
	outtextxy(10 + Otypetext1x, Otypetext1y + 10, "int T = log2(N) - (1 << (int)log2(N) == N);");

	outtextxy(10 + Otypetext1x, Otypetext1y + 40, "for (int t = T; t >= 0; --t) {");
	outtextxy(40 + Otypetext1x, Otypetext1y + 50, "int p = 1 << t;");
	outtextxy(40 + Otypetext1x, Otypetext1y + 60, "int q = 1 << T;");
	outtextxy(40 + Otypetext1x, Otypetext1y + 70, "int r = 0;");
	outtextxy(40 + Otypetext1x, Otypetext1y + 80, "int d = p;");

	outtextxy(40 + Otypetext1x, Otypetext1y + 110, "while (d) {");
	outtextxy(70 + Otypetext1x, Otypetext1y + 140, "for (int i = 0; i < N - d; ++i)");
	outtextxy(100 + Otypetext1x, Otypetext1y + 160, "if ((i & p) == r && R[i + 1].Key > R[i + d + 1].Key)");
	outtextxy(130 + Otypetext1x, Otypetext1y + 190, "swap(R[i + 1], R[i + d + 1]);");

	outtextxy(70 + Otypetext1x, Otypetext1y + 210, "d = q - p;");
	outtextxy(70 + Otypetext1x, Otypetext1y + 220, "q = q / 2;");
	outtextxy(70 + Otypetext1x, Otypetext1y + 230, "r = p;");
	outtextxy(40 + Otypetext1x, Otypetext1y + 240, "}");
	outtextxy(10 + Otypetext1x, Otypetext1y + 260, "}");
	setfontcolor(4);
}

void drawstep(Record R[], int t, int p, int q, int r, int d, int i, int stepth) {
	if (stepth >= 1) {
		if (stepth == 1) setfontcolor(9);
		outtextxy(10 + Otypetext2x, Otypetext2y + 40, "t = " + to_string(t));
		outtextxy(40 + Otypetext2x, Otypetext2y + 50, "p = " + to_string(p));
		outtextxy(40 + Otypetext2x, Otypetext2y + 60, "q = " + to_string(q));
		outtextxy(40 + Otypetext2x, Otypetext2y + 70, "r = " + to_string(r));
		outtextxy(40 + Otypetext2x, Otypetext2y + 80, "d = " + to_string(d));
		outtextxy(40 + Otypetext2x, Otypetext2y + 110, "Kiem tra (" + to_string(d) + " > 0)");
		setfontcolor(4);
	}

	if (stepth >= 2 && stepth <= 4) {
		if (stepth == 2) setfontcolor(9);
		outtextxy(70 + Otypetext2x, Otypetext2y + 140, "i = " + to_string(i));
		setfontcolor(4);
	}

	if (stepth >= 3 && stepth <= 4) {
		if (stepth == 3) setfontcolor(9);
		outtextxy(100 + Otypetext2x, Otypetext2y + 160, "Kiem tra (("
			+ to_string(i) + " & "
			+ to_string(p) + ") == "
			+ to_string(i) + " && "
			+ to_string(R[i + 1].Key) + " > "
			+ to_string(R[i + d + 1].Key) + ")");
		setfontcolor(4);
	}

	if (stepth == 4) {
		setfontcolor(9);
		outtextxy(130 + Otypetext2x, Otypetext2y + 190, "swap(R["
			+ to_string(i + 1) + "], R["
			+ to_string(i + d + 1) + "]);");
		setfontcolor(4);
	}

	if (stepth == 5) {
		setfontcolor(9);
		outtextxy(70 + Otypetext2x, Otypetext2y + 210, "d = " + to_string(q - p));
		outtextxy(70 + Otypetext2x, Otypetext2y + 220, "q = " + to_string(q / 2));
		outtextxy(70 + Otypetext2x, Otypetext2y + 230, "r = " + to_string(p));
		setfontcolor(4);
	}

	Sleep(1500);
}


void draw(Record R[], int N, int j, int k) {
	setcolor(4), setfontcolor(4);

	outtextxy(Otypenumberx - 81, Otypenumbery - 10, "Index");
	outtextxy(Otypenumberx - 81, Otypenumbery, "R[Index]Key");

	for (int i = 1; i <= N; ++i)
	{
		if (i == k || i == j) setcolor(9), setfontcolor(9);
		outnumberxy(Otypenumberx + 54 * i, Otypenumbery - 10, i);
		outnumberxy(Otypenumberx + 54 * i, Otypenumbery, R[i].Key);

		rectangle(Otyperectx + 61 * i, Otyperecty - 15 * R[i].Key,
			Otyperectx + 50 + 61 * i, Otyperecty);

		setcolor(4), setfontcolor(4);
	}
}
void draw2(Record R[], int N, int j, int k)
{
	system("cls");
	text();
	draw(R, N, j, k);
	Sleep(50);
	draw(R, N, j, k);
	Sleep(50);
}


void MergeSort(Record R[], int N) {
	draw(R, N, -1, -1);

	int T = log2(N) - (1 << (int)log2(N) == N);
	for (int t = T; t >= 0; --t) {
		int p = 1 << t;
		int q = 1 << T;
		int r = 0;
		int d = p;
		draw2(R, N, -1, -1);
		drawstep(R, t, p, q, r, d, -1, 1);

		while (d) {
			draw2(R, N, -1, -1);
			drawstep(R, t, p, q, r, d, -1, 2);
			for (int i = 0; i < N - d; ++i) {
				draw2(R, N, i + 1, i + d + 1);
				drawstep(R, t, p, q, r, d, i, 3);
				if ((i & p) == r && R[i + 1].Key > R[i + d + 1].Key) {
					draw2(R, N, i + 1, i + d + 1);
					drawstep(R, t, p, q, r, d, i, 4);
					swap(R[i + 1], R[i + d + 1]);
				}
			}
			draw2(R, N, -1, -1);
			drawstep(R, t, p, q, r, d, -1, 5);
			d = q - p;
			q = q / 2;
			r = p;
		}
	}
	draw2(R, N, -1, -1);
}

int main() {
	initgraph();
	DisableSelection();
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	/*
	int N = 16;
	Record R[111];

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

	MergeSort(R, N);

	_getch(); 
	system("cls");
	return 0;
}