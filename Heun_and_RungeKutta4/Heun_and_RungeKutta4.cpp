#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846
#define M_E 2.71828182845904523536

using namespace std;

double f(double x, double y) {
	return (y/x)*(log(y)-log(x));

}

int main() {
	double x0 = 1;
	double y0 = pow(M_E, 2);
	double b = 3;
	double h = 0.1;

	double N = 1 + (b - x0) / h;

	double* y = new double[N];
	double* x = new double[N];

	x[0] = x0;
	y[0] = y0;

	cout << "Metoda Heuna" << endl;
	for (int i = 1; i < N; i++) {
		double k1 = f(x[i - 1], y[i - 1]);
		double k2 = f(x[i - 1] + h, y[i - 1] + h * k1);

		y[i] = y[i - 1] + (h / 2) * (k1 + k2);
		x[i] = x[i - 1] + h;
		printf("y%d = %lf\n", i, y[i]);
	}

	cout << "\nMetoda RK4" << endl;
	for (int i = 1; i < N; i++) {
		double k1 = h * f(x[i - 1], y[i - 1]);
		double k2 = h * f(x[i - 1] + 0.5 * h, y[i - 1] + 0.5 * k1);
		double k3 = h * f(x[i - 1] + 0.5 * h, y[i - 1] + 0.5 * k2);
		double k4 = h * f(x[i - 1] + h, y[i - 1] + k3);

		y[i] = y[i - 1] + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

		x[i] = x[i - 1] + h;
		printf("y%d = %lf\n", i, y[i]);
	}

	return 0;
}