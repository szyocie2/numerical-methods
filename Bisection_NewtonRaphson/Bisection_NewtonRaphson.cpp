#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {//funkcja pierwotna
	return 1.12 * pow(x, 5) - sqrt(pow(x,7))+(7.89*log(x));
}

double pf(double x) {//pochodna
	return ((560 * log(10)*pow(x,5)+789)/(100*log(10)*x))-((7*pow(x, (5/2)))/2);
}

double bisekcja(double x, double a, double b, double dokladnosc) {

	while (fabs(a - b) > dokladnosc) {
		x = (a + b) / 2;
		if (f(x) * f(a) < 0) b = x;
		if (f(x) * f(b) < 0) a = x;
	}

	return x = (a + b) / 2;;
}

double newton_raphson(double x, double precyzja) {
	double x_nastepny = x - f(x) / pf(x);
	while ((fabs(f(x)) > precyzja) && (fabs(x_nastepny - x) > precyzja)) {
		x = x_nastepny;
		x_nastepny = x_nastepny - f(x_nastepny) / pf(x);
	}
	return x_nastepny;
}


int main() {

	double a(0.2), b(1.6);
	double x = (a + b) / 2;;
	double dokladnosc = 0.0000001;

	if (f(x) == 0) { cout << "x0 = " << x; return 0; }

	printf("bisekcja x0 = %.7f\n", bisekcja(x, a, b, dokladnosc));
	printf("     N-R x0 = %.7f\n", newton_raphson(x, dokladnosc));

	return 0;
}