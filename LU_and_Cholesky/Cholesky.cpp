#include <iostream>
#include <cmath>

using namespace std;

int main() {

	//double tab[3][4] = {	{  4, -2,  2, -6},
	//						{ -2,  2,  2,  4},
	//						{  2,  2, 14,  0} };
	//int n = 3;

	//double tab[3][4] = { {  2, -3, -1, 10},
	//						{  4, -7,  2,  9},
	//						{ -2, -1, 15,-48} };
	//int n = 3;

	//double tab[4][5] = {	{   25,  15,  20, -15, -75  },
	//						{	15,  13,  20, -15, -65  },
	//						{	20,	 20,  48,  -4, -76  },
	//						{  -15, -15,  -4,  59, 137  }};
	//int n = 4;
	
	//double tab[4][5] = {	{   4,   8,   4,  8,   0  },
	//						{	8,  20,  -2, 12,  34  },
	//						{	4,	-2,  54,  8, -80  },
	//						{   8,	12,   8, 40, -84  }};
	//int n = 4;

	//double tab[3][4] = {	{  1,  2,  3, 1},
	//						{  2,  8, 10, 3},
	//						{  3, 10, 22, 7} };
	//int n = 3;

	//double tab[6][7] = { { 4, 2,  1, 3,  0, 4, 3 },
	//					{ 1,  3,  5,  1,  0, 3, 0 },
	//					{ 3,  2,  3,  2,  4, 5, 4 },
	//					{ 3,  3,  3,  5,  1, 0, 5 },
	//					{ 2,  1,  0,  4,  20, 2, 4 },
	//					{ 4, 3,  4,  4,  4, 12, 5 } };
	//int n = 6;

	double tab[6][7] = {	{ 50.53,	4.35,		5.3,	5.5,    4.63,   3.62,	 4.2 },
							{ 4.35,		68.23,		63.2,	6.3,    4.62,   0.35,	4.32 },
							{ 5.3,		63.2,	  60.32,	 2.63,  5.3,    6.23,	 4 },
							{ 5.5,		6.3,	  2.63,		41.98,	3.85,   8.5,	8.5 },
							{ 4.63,		4.62,	  5.3,		3.85,	156.7,    9.53,	0.4 },
							{ 3.62,		0.35,	   6.23,	8.5,	9.53,   180.3,	 6.4 } };
	int n = 6;


	//zainicjowanie dwuwymiarowej tablicy dynamicznej L
	double** L = new double* [n];
	for (int i = 0; i < n; i++) {
		L[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			L[i][j] = 0.0;
		}
	}

	//obliczenie L
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			double sum = 0;
			if (j == i) {
				for (int k = 0; k < j; k++)
					sum += pow(L[j][k], 2);
				L[j][j] = sqrt(tab[j][j] - sum);
			}
			else {
				for (int k = 0; k < j; k++)
					sum += L[i][k] * L[j][k];
				L[i][j] = (tab[i][j] - sum) / L[j][j];
			}
		}
	}

	//zastapnie w tab 3x3 = L-ami
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "\t" << L[i][j];
		}
		cout << endl;
	}



	//zastapnie w tab 3x3 = L-ami
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tab[i][j] = L[i][j];
		}
	}

	// obliczanie y-ów z macierzy trójk¹tnej dolnej
	double* y = new double[n];

	for (int i = 0; i < n; i++) {
		y[i] = tab[i][n];
		for (int j = 0; j < i; j++) {
			y[i] -= tab[i][j] * y[j];
		}
		y[i] /= tab[i][i];
	}
	
	//transponowanie macierzy L do tab
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tab[j][i] = L[i][j];
		}
		tab[i][n] = y[i];
	}

	// obliczanie x-ów z macierzy trójk¹tnej górnej
	double* x = new double[n];

	for (int i = n - 1; i >= 0; i--) {
		x[i] = tab[i][n];
		for (int j = i + 1; j < n; j++) {
			x[i] -= tab[i][j] * x[j];
		}
		x[i] /= tab[i][i];
	}

	//wypisanie x-ów
	for (int i = 0; i < n; i++) {
		cout << "\tx" << i + 1 << " = " << x[i] << endl;
	}

	for (int i = 0; i < n; i++) {
		delete[] L[i];
	}
	delete[] L;

	return 0;
}