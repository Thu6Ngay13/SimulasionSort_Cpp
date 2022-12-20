#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <string>

const int Otypetext1x = 100;
const int Otypetext1y = 0;

const int Otypetext2x = 500;
const int Otypetext2y = 0;

const int Otypenumberx = 575;
const int Otypenumbery = 365;

const int Otyperectx = 630;
const int Otyperecty = 900;

struct Record {
	char data;
	int Key;
};

void text() {
	setfontcolor(2);
	outtextxy(10 + Otypetext1x, Otypetext1y + 10, "int I, J;");
	outtextxy(10 + Otypetext1x, Otypetext1y + 20, "Record P;");
	outtextxy(10 + Otypetext1x, Otypetext1y + 30, "for (int L = 0; L < N; ++L) {");
	outtextxy(40 + Otypetext1x, Otypetext1y + 60, "while (R[L].Key > 0) {");
	outtextxy(70 + Otypetext1x, Otypetext1y + 90, "I = L;");
	outtextxy(70 + Otypetext1x, Otypetext1y + 100, "J = L;");
	outtextxy(70 + Otypetext1x, Otypetext1y + 110, "P = R[L];");
	outtextxy(70 + Otypetext1x, Otypetext1y + 120, "while (R[J].Key > 0) {");
	outtextxy(100 + Otypetext1x, Otypetext1y + 150, "++J;");
	outtextxy(100 + Otypetext1x, Otypetext1y + 160, "while (P.Key <= R[J].Key) J++;");
	outtextxy(100 + Otypetext1x, Otypetext1y + 170, "if (R[J].Key > 0) {");
	outtextxy(130 + Otypetext1x, Otypetext1y + 200, "R[I] = R[J];");
	outtextxy(130 + Otypetext1x, Otypetext1y + 210, "I++;");
	outtextxy(130 + Otypetext1x, Otypetext1y + 220, "R[J] = R[I];");
	outtextxy(100 + Otypetext1x, Otypetext1y + 230, "}");
	outtextxy(70 + Otypetext1x, Otypetext1y + 240, "}");
	outtextxy(70 + Otypetext1x, Otypetext1y + 250, "P.Key = -P.Key;");
	outtextxy(70 + Otypetext1x, Otypetext1y + 260, "R[I] = P;");
	outtextxy(40 + Otypetext1x, Otypetext1y + 270, "}");
	outtextxy(40 + Otypetext1x, Otypetext1y + 280, "R[L].Key = -R[L].Key;");
	outtextxy(10 + Otypetext1x, Otypetext1y + 290, "}");
	setfontcolor(4);
}

void drawstep(Record R[], Record P, int L, int I, int J, int stepth) {
	if (stepth >= 1) {
		if (stepth == 1) setfontcolor(9);
		outtextxy(Otypetext2x + 10, Otypetext2y + 30, "L = " + to_string(L));
		outtextxy(Otypetext2x + 10, Otypetext2y + 60, "Kiem Tra (" + to_string(R[L].Key) + " > 0)");
		setfontcolor(4);
	}

	if (stepth >= 2 && stepth <= 6) {
		if (stepth == 2) setfontcolor(9);
		outtextxy(Otypetext2x + 40, Otypetext2y + 90, "Gan I = " + to_string(L));
		outtextxy(Otypetext2x + 40, Otypetext2y + 100, "Gan J = " + to_string(L));
		outtextxy(Otypetext2x + 40, Otypetext2y + 110, "Gan P = R[" + to_string(L) + "]");
		setfontcolor(4);
	}

	if (stepth >= 3 && stepth <= 6) {
		if (stepth == 3) setfontcolor(9);
		outtextxy(Otypetext2x + 40, Otypetext2y + 120, "Kiem Tra (" + to_string(R[J].Key) + " > 0)");
		setfontcolor(4);
	}

	if (stepth >= 4 && stepth <= 5) {
		if (stepth == 4) setfontcolor(9);
		outtextxy(Otypetext2x + 70, Otypetext2y + 150, "J++");
		outtextxy(Otypetext2x + 70, Otypetext2y + 160, "Trong khi (" + to_string(P.Key) + " <= " + to_string(R[J].Key) + ") J++");
		outtextxy(Otypetext2x + 70, Otypetext2y + 170, "Kiem tra (" + to_string(R[J].Key) + " > 0)");
		setfontcolor(4);
	}

	if (stepth == 5) {
		if (stepth == 5) setfontcolor(9);
		outtextxy(Otypetext2x + 100, Otypetext2y + 200, "R[" + to_string(I) + "] = R[" + to_string(J) + "]");
		outtextxy(Otypetext2x + 100, Otypetext2y + 210, "I++");
		outtextxy(Otypetext2x + 100, Otypetext2y + 220, "R[" + to_string(J) + "] = R[" + to_string(I + 1) + "]");
		setfontcolor(4);
	}

	if (stepth == 6) {
		if (stepth == 6) setfontcolor(9);
		outtextxy(Otypetext2x + 40, Otypetext2y + 250, "P.Key = -P.Key");
		outtextxy(Otypetext2x + 40, Otypetext2y + 260, "R[" + to_string(I) + "] = P");
		setfontcolor(4);
	}

	if (stepth == 7) {
		if (stepth == 7) setfontcolor(9);
		outtextxy(Otypetext2x + 10, Otypetext2y + 280, "R[" + to_string(L) + "].Key = -R[" + to_string(L) + "].Key");
		setfontcolor(4);
	}

	Sleep(1000);
}

void positive(int i, int x) {
	outnumberxy(Otypenumberx + 55 * i, Otypenumbery - 10, i);
	outnumberxy(Otypenumberx + 55 * i, Otypenumbery, x);
	rectangle(Otyperectx + 61 * i, Otyperecty - 15 * x,
		Otyperectx + 50 + 61 * i, Otyperecty);

}

void negative(int i, int x) {
	outnumberxy(Otypenumberx + 55 * i, Otypenumbery - 10, i);
	outnumberxy(Otypenumberx + 55 * i, Otypenumbery, x);
	rectangle(Otyperectx + 61 * i, Otyperecty,
		Otyperectx + 50 + 61 * i, Otyperecty - 15 * x);
}

void drawcolumn(Record R[], int N, int L) {
	system("cls");
	text();
	setcolor(4), setfontcolor(4);
	outtextxy(Otypenumberx - 61, Otypenumbery - 10, "Index");
	for (int i = 0; i < N; ++i) {
		if (i == L) setcolor(9), setfontcolor(9);
		if (R[i].Key < 0) negative(i, R[i].Key);
		else positive(i, R[i].Key);
		setcolor(4), setfontcolor(4);
	}
	Sleep(100);
}

void oneWay_QuickSort(Record R[], int N) {
	int I = -1, J = -1;
	Record P = R[0];

	for (int L = 0; L < N; ++L) {

		drawcolumn(R, N, L);
		drawstep(R, P, L, I, J, 1);
		while (R[L].Key > 0) {

			drawcolumn(R, N, L);
			drawstep(R, P, L, I, J, 2);

			I = L;
			J = L;
			P = R[L];

			drawcolumn(R, N, L);
			drawstep(R, P, L, I, J, 3);
			while (R[J].Key > 0) {

				drawcolumn(R, N, L);
				drawstep(R, P, L, I, J, 4);
				++J;
				while (P.Key <= R[J].Key) J++;
				if (R[J].Key > 0) {

					drawcolumn(R, N, L);
					drawstep(R, P, L, I, J, 5);
					R[I] = R[J]; I++;
					R[J] = R[I];
				}
			}

			drawcolumn(R, N, L);
			drawstep(R, P, L, I, J, 6);
			P.Key = -P.Key;
			R[I] = P;
		}

		drawcolumn(R, N, L);
		drawstep(R, P, L, I, J, 7);
		R[L].Key = -R[L].Key;
	}
	drawcolumn(R, N, -1);
}

int main()
{
	initgraph();
	DisableSelection();
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	int N; N = 10;
	Record R[100];

	R[0].Key = 4;
	R[1].Key = 2;
	R[2].Key = 5;
	R[3].Key = 6;
	R[4].Key = 3;
	R[5].Key = 1;
	R[6].Key = 8;
	R[7].Key = 7;
	R[8].Key = 10;
	R[9].Key = 9;
	R[10].Key = -1;


	oneWay_QuickSort(R, N);

	char c = getchar();
	return 0;
}