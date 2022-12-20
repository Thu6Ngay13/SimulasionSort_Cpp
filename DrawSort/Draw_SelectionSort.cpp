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
	outtextxy(10 + Otypetext1x, Otypetext1y + 10, "for (int j = N; j >= 2; --j) {");
	outtextxy(40 + Otypetext1x, Otypetext1y + 40, "pos = j;");
	outtextxy(40 + Otypetext1x, Otypetext1y + 50, "P = R[j];");

	outtextxy(40 + Otypetext1x, Otypetext1y + 60, "for (int i = j; i >= 1; --i) {");
	outtextxy(70 + Otypetext1x, Otypetext1y + 90, "if (R[i].Key > P.Key) {");

	outtextxy(100 + Otypetext1x, Otypetext1y + 110, "P = R[i];");
	outtextxy(100 + Otypetext1x, Otypetext1y + 130, "pos = i;");
	outtextxy(70 + Otypetext1x, Otypetext1y + 140, "}");
	outtextxy(40 + Otypetext1x, Otypetext1y + 150, "}");
	outtextxy(40 + Otypetext1x, Otypetext1y + 160, "Record temp = R[j];");
	outtextxy(40 + Otypetext1x, Otypetext1y + 170, "R[j] = R[pos];");
	outtextxy(40 + Otypetext1x, Otypetext1y + 180, "R[pos] = temp;");
	outtextxy(10 + Otypetext1x, Otypetext1y + 200, "}");
	setfontcolor(4);
}

void drawstep(Record R[], Record P, int j, int i, int pos, int stepth) {
	if (stepth >= 1) {
		if (stepth == 1) setfontcolor(9);
		outtextxy(10 + Otypetext2x, Otypetext2y + 10, "j = " + to_string(j));
		outtextxy(40 + Otypetext2x, Otypetext2y + 40, "pos = " + to_string(j));
		outtextxy(40 + Otypetext2x, Otypetext2y + 50, "P = R[" + to_string(j) + "]");
		setfontcolor(4);
	}
	if (stepth >= 2 && stepth <= 3) {
		if (stepth == 2) setfontcolor(9);
		outtextxy(40 + Otypetext2x, Otypetext2y + 60, "i = " + to_string(i));
		outtextxy(70 + Otypetext2x, Otypetext2y + 90, "Kiem tra (" + to_string(R[i].Key) + " > " + to_string(P.Key) + ")");
		setfontcolor(4);
	}
	if (stepth == 3) {
		setfontcolor(9);
		outtextxy(100 + Otypetext2x, Otypetext2y + 110, "P = R[" + to_string(i) + "];");
		outtextxy(100 + Otypetext2x, Otypetext2y + 130, "pos = " + to_string(i));
		setfontcolor(4);
	}
	if (stepth == 4) {
		setfontcolor(9);
		outtextxy(40 + Otypetext2x, Otypetext2y + 160, "Record temp = R[" + to_string(j) + "];");
		outtextxy(40 + Otypetext2x, Otypetext2y + 170, "R[" + to_string(j) + "] = R[" + to_string(pos) + "];");
		outtextxy(40 + Otypetext2x, Otypetext2y + 180, "R[" + to_string(pos) + "] = temp;");
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

void draw2(Record R[], int N, int j, int k) {
	system("cls");
	text();
	draw(R, N, j, k);
	Sleep(50);
	draw(R, N, j, k);
	Sleep(50);
}


void SelectionSort(Record R[], int N) {
	int pos;
	Record P;

	draw(R, N, -1, -1);

	for (int j = N; j >= 2; --j) {
		pos = j;
		P = R[j];
		draw2(R, N, -1, -1);
		drawstep(R, P, j, -1, -1, 1);

		for (int i = j; i >= 1; --i) {
			draw2(R, N, -1, -1);
			drawstep(R, P, j, i, -1, 2);

			if (R[i].Key > P.Key) {
				draw2(R, N, j, pos);
				drawstep(R, P, j, i, -1, 3);
				P = R[i];
				pos = i;
			}
		}
		draw2(R, N, j, pos);
		drawstep(R, P, j, -1, pos, 4);
		Record temp = R[j];
		R[j] = R[pos];
		R[pos] = temp;
		draw2(R, N, j, pos);

	}

	draw2(R, N, -1, -1);
}




int main() {
	initgraph();
	DisableSelection();
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	/*
	int N = 10;
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
	R[10].Key = 8;
	*/

	cout << "Nhap vao so luong phan tu: ";
	int N; cin >> N;
	Record R[100];
	cout << "Nhap vao gia tri cac phan tu: ";
	for (int i = 1; i <= N; ++i) cin >> R[i].Key;

	SelectionSort(R, N);

	_getch();
	system("cls");
	return 0;
}