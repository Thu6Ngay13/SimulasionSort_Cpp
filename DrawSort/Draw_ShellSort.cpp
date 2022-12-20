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
	outtextxy(10 + Otypetext1x, Otypetext1y + 10, "if (N == 0) return;");

	outtextxy(10 + Otypetext1x, Otypetext1y + 40, "int T = log2(N) + (1 << (int)log2(N) < N);");
	outtextxy(10 + Otypetext1x, Otypetext1y + 50, "int H[T];");
	outtextxy(10 + Otypetext1x, Otypetext1y + 60, "for (int i = 0; i < T; ++i)");
	outtextxy(40 + Otypetext1x, Otypetext1y + 70, "H[i] = 1 << i;");

	outtextxy(10 + Otypetext1x, Otypetext1y + 100, "int k;");
	outtextxy(10 + Otypetext1x, Otypetext1y + 110, "for (int s = T - 1; s >= 0; --s) {");

	outtextxy(40 + Otypetext1x, Otypetext1y + 140, "k = H[s];");
	outtextxy(40 + Otypetext1x, Otypetext1y + 150, "int i;");
	outtextxy(40 + Otypetext1x, Otypetext1y + 160, "Record P;");
	outtextxy(40 + Otypetext1x, Otypetext1y + 170, "for (int j = k; j < N; ++j) {");

	outtextxy(70 + Otypetext1x, Otypetext1y + 200, "i = j - k;");
	outtextxy(70 + Otypetext1x, Otypetext1y + 210, "P = R[j];");
	outtextxy(70 + Otypetext1x, Otypetext1y + 220, "while (i >= 0 && P.Key < R[i].Key) {");

	outtextxy(100 + Otypetext1x, Otypetext1y + 250, "R[i + k] = R[i];");
	outtextxy(100 + Otypetext1x, Otypetext1y + 260, "i = i - k;");
	outtextxy(70 + Otypetext1x, Otypetext1y + 270, "}");
	outtextxy(70 + Otypetext1x, Otypetext1y + 280, "R[i + k] = P;");
	outtextxy(40 + Otypetext1x, Otypetext1y + 290, "}");
	outtextxy(10 + Otypetext1x, Otypetext1y + 300, "}");
	setfontcolor(4);
}

void drawstep(Record R[], Record P, int H[], int s, int i, int j, int stepth) {
	if (stepth >= 1) {
		if (stepth == 1) setfontcolor(9);
		outtextxy(Otypetext2x + 10, Otypetext2y + 110, "s = " + to_string(s));
		outtextxy(Otypetext2x + 40, Otypetext2y + 140, "k = " + to_string(H[s]));
		setfontcolor(4);
	}

	if (stepth >= 2) {
		if (stepth == 2) setfontcolor(9);
		outtextxy(40 + Otypetext2x, Otypetext2y + 170, "j = " + to_string(j));
		outtextxy(70 + Otypetext2x, Otypetext2y + 200, "i = " + to_string(i));
		outtextxy(70 + Otypetext2x, Otypetext2y + 210, "P = R[" + to_string(j) + "]");
		if (stepth == 4) outtextxy(70 + Otypetext2x, Otypetext2y + 220, "Kiem tra (" + to_string(i) +
			" >= 0)");
		else
			outtextxy(70 + Otypetext2x, Otypetext2y + 220, "Kiem tra (" + to_string(i) +
				" >= 0) && (" + to_string(P.Key) + " < " + to_string(R[i].Key) + ")");
		setfontcolor(4);
	}

	if (stepth == 3) {
		setfontcolor(9);
		outtextxy(100 + Otypetext2x, Otypetext2y + 250, "R[" + to_string(i + H[s]) +
			"] = R[" + to_string(i) + "]");
		outtextxy(100 + Otypetext2x, Otypetext2y + 260, "i = " + to_string(i - H[s]));
		setfontcolor(4);
	}

	if (stepth >= 4) {
		if (stepth == 4) setfontcolor(9);
		outtextxy(70 + Otypetext2x, Otypetext2y + 280, "R[" + to_string(i + H[s]) + "] = P");
		setfontcolor(4);
	}

	Sleep(1500);
}

void draw(Record R[], int N, int j, int k) {
	setcolor(4), setfontcolor(4);

	outtextxy(Otypenumberx - 81, Otypenumbery - 10, "Index");
	outtextxy(Otypenumberx - 81, Otypenumbery, "R[Index]Key");

	for (int i = 0; i < N; ++i)
	{
		if (i == j + k || i == j) setcolor(9), setfontcolor(9);

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

void ShellSort(Record R[], int N)
{
	if (N < 2) return;

	int dem = 0;
	draw2(R, N, -1, -1);

	int T = log2(N) + (1 << (int)log2(N) < N);
	int H[1000];
	for (int i = 0; i < T; ++i)
		H[i] = 1 << i;

	int k;
	for (int s = T - 1; s >= 0; --s) {

		draw2(R, N, -1, -1);
		drawstep(R, R[0], H, s, -1, -1, 1);
		k = H[s];
		int i;
		Record P;
		for (int j = k; j < N; ++j) {

			draw2(R, N, -1, -1);
			drawstep(R, R[j], H, s, j - k, j, 2);
			i = j - k;
			P = R[j];
			while (i >= 0 && P.Key < R[i].Key)
			{

				draw2(R, N, -1, -1);
				drawstep(R, P, H, s, i, j, 3);
				R[i + k] = R[i];
				i = i - k;
				dem += 1;
			}

			draw2(R, N, i + k * dem, k);
			drawstep(R, P, H, s, i, j, 4);
			R[i + k] = P;
			dem = 0;
		}
	}
	draw2(R, N, -1, -1);
}

int main() {
	initgraph();
	DisableSelection();
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	/*
	int N = 10;
	Record R[10];

	R[0].Key = 7;
	R[1].Key = 3;
	R[2].Key = 8;
	R[3].Key = 2;
	R[4].Key = 6;
	R[5].Key = 2;
	R[6].Key = 1;
	R[7].Key = 9;
	R[8].Key = 3;
	R[9].Key = 1;
	*/

	cout << "Nhap vao so luong phan tu: ";
	int N; cin >> N;
	Record R[100];
	cout << "Nhap vao gia tri cac phan tu: ";
	for (int i = 0; i < N; ++i) cin >> R[i].Key;

	ShellSort(R, N);

	_getch();
	system("cls");
	return 0;
}