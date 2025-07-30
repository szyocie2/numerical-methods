#include <iostream>
#include <fstream>
#include <cmath>
#include <string> //getline

using namespace std;

void prostokaty(int n, double xp, double xk) {
	double dx = (xk - xp) / n;;

	double* fx = new double[n];

	double temp = dx;
	double wynik = 0;

	for (int i = 0; i < n; i++) {
		fx[i] = pow((xp + temp), 3) + 2;
		wynik += fx[i];
		temp += dx;
	}
	wynik *= dx;

	cout << "Metoda 1 = " << wynik << endl;
}

void trapezy(int n, double xp, double xk) {
	double dx = (xk - xp) / n;;


	double temp = 0;
	double wynik = 0;

	double a, b;

	for (int i = 0; i < n; i++) {
		a = pow((xp + temp), 3) + 2;
		b = pow((xp + temp + dx), 3) + 2;

		wynik += ((a + b) / 2) * dx;
		temp += dx;
	}

	cout << "Metoda 2 = " << wynik << endl;
}

void simpson(int n, double xp, double xk) {
	double temp = 0;
	double wynik = 0;
	double h = (xk - xp) / n;;

	double a, b, c;

	for (int i = 0; i < n - 2; i++) {
		a = pow((xp + temp), 3) + 2;
		b = pow((xp + temp + h), 3) + 2;
		c = pow((xp + temp + 2 * h), 3) + 2;

		temp += 2 * h;
		wynik += ((a + (4 * b) + c) * (h / 3));

	}
	cout << "Metoda 3 = " << wynik << endl;

}

double fRand(double fMin, double fMax) {
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

void monteCarlo(int n, double xp, double xk) {
	double temp = 0;
	double wynik = 0;

	double* fx = new double[n];
	double a;
	fx[0] = NULL;

	//fx[0] = 1.5;
	//fx[1] = 2.6;
	//fx[2] = 3.8;
	//fx[3] = 4.5;


	for (int i = 0; i < n; i++) {
		fx[i] = fRand(xp, xk);
		cout << "punkt nr " << i << " = " << fx[i] << "\n";
		a = pow((fx[i]), 3) + 2;
		wynik += a / n;
	}
	wynik = wynik * fabs(xk - xp);
	cout << "Metoda 4 = " << wynik << endl;

}

int main() {

	prostokaty(3, 1, 4);
	trapezy(3, 1, 4);
	simpson(4, 1, 5);
	monteCarlo(4, 1, 5);

	return 0;
}
