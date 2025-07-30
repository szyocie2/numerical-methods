#include <iostream>
#define _USE_MATH_DEFINES // for C++ M_E - sta³a eulera
#include <math.h>

using namespace std;

double f(double x, double y) {
	return 2*y;
}

int main() {
	double x0 = 0;
	double y0 = 1;
	double b = 2;
	double h = 0.25;

	int N = (b - x0) / h;
	N += 1;

	double* y = new double[N];
	double* x = new double[N];

	x[0] = x0;
	y[0] = y0;

	for (int i = 1; i < N; i++) {
		y[i] = y[i - 1] + h * f(x[i - 1], y[i - 1]);
		x[i] = x[i - 1] + h;
		printf("y%d = %lf\n", i, y[i]);
	}



	delete[] y;
	delete[] x;

	return 0;
}