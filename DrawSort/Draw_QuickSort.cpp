#include "graphics.h"
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <math.h>
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
	int Key;
};

struct Data {
	int l, r;
	Data* next;
};

void draw(Record R[], int N, int l, int j, int k) {
	setcolor(4), setfontcolor(4);

	outtextxy(Otypenumberx - 81, Otypenumbery - 10, "Index");
	outtextxy(Otypenumberx - 81, Otypenumbery, "R[Index]Key");

	for (int i = 1; i <= N; ++i)
	{
		if (i == l)	setcolor(7), setfontcolor(7);
		if (i == j)	setcolor(11), setfontcolor(11);
		if (i == k) setcolor(9), setfontcolor(9);

		outnumberxy(Otypenumberx + 54 * i, Otypenumbery - 10, i);
		outnumberxy(Otypenumberx + 54 * i, Otypenumbery, R[i].Key);

		rectangle(Otyperectx + 61 * i, Otyperecty - 15 * R[i].Key,
			Otyperectx + 50 + 61 * i, Otyperecty);

		setcolor(4), setfontcolor(4);
	}
}
void draw2(Record R[], int N, int l, int j, int k)
{
	system("cls");
	draw(R, N, l, j, k);
	Sleep(10);
	draw(R, N, l, j, k);
	Sleep(1000);
}


struct STACK {
	Data* top;

	void init() { top = nullptr; }
	bool isEmpty() { return top == nullptr; }
	bool insertNode(int l, int r) {
		Data* x = new Data();
		x->l = l;
		x->r = r;
		x->next = nullptr;
		if (top == nullptr) {
			top = x;
			return true;
		}
		x->next = top;
		top = x;
		return true;
	}
	Data* deleteNode() {
		if (top == nullptr) return nullptr;

		Data* result = new Data();
		result->l = top->l;
		result->r = top->r;
		result->next = nullptr;

		Data* temp = top->next;
		delete top;
		top = temp;

		return result;
	}
};

bool check(Record R[], int N) {
	for (int i = 2; i <= N; ++i)
		if (R[i - 1].Key > R[i].Key) return false;
	return true;
}


void QuickSort(Record R[], int N) {
	draw2(R, N, -1, -1, -1);

	int M = 1, l = 1, r = N;
	STACK s; s.init();
	s.insertNode(1, N);

	int dem = 0;
	while (!s.isEmpty())
	{
		int i = l, j = r + 1;
		Record P = R[l];

		while (j > i)
		{
			i++;
			draw2(R, N, l, -1, i);

			while (R[i].Key < P.Key)
			{
				i++;
				if (i >= 1 && i <= N)
					draw2(R, N, l, -1, i);
			}

			j--;
			draw2(R, N, l, j, -1);
			while (P.Key < R[j].Key)
			{
				j--;
				draw2(R, N, l, j, -1);
			}

			if (j > i)
			{
				draw2(R, N, l, j, i);
				swap(R[i], R[j]);
				draw2(R, N, l, j, i);
			}
		}

		if (l != j)
			draw2(R, N, l, j, -1);
		swap(R[l], R[j]);
		if (l != j)
			draw2(R, N, l, j, -1);

		if (r - j >= j - l && j - l > M) {
			s.insertNode(j + 1, r);
			r = j - 1;
			continue;
		}
		if (j - l > r - j && r - j > M) {
			s.insertNode(l, j - 1);
			l = j + 1;
			continue;
		}
		if (r - j > M && M >= j - l) {
			l = j + 1;
			continue;
		}
		if (j - l > M && M >= r - j) {
			r = j - 1;
			continue;
		}

		if (s.isEmpty()) break;

		Data* top = s.deleteNode();
		l = top->l, r = top->r;
		delete top;
	}

	/*	for (int j = 2; j <= N; ++j) {
			Record P;
			int i;
			if (R[j - 1].Key > R[j].Key)
			{
				draw2(R, N, j - 1, j);
				P = R[j];
				i = j - 1;
				R[i + 1] = R[i];
				i = i - 1;
				while (R[i].Key <= P.Key)
				{
					draw2(R, N, j, i);
					R[i + 1] = R[i];
					i = i - 1;
				}
				R[i + 1] = P;
				draw2(R, N, j, i + 1);
			}
		}
	*/
	draw2(R, N, -1, -1, -1);
}

int main() {
	initgraph();
	DisableSelection();
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	/*
	int N = 10;
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
	R[10].Key = 8;
	*/

	cout << "Nhap vao so luong phan tu: ";
	int N; cin >> N;
	Record R[100];
	R[0].Key = INT_MIN;
	R[N + 1].Key = INT_MAX;
	cout << "Nhap vao gia tri cac phan tu: ";
	for (int i = 1; i <= N; ++i) cin >> R[i].Key;

	QuickSort(R, N);

	_getch();
	system("cls");
	return 0;
}
