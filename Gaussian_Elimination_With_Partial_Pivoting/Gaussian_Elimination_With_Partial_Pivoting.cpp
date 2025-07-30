#include <iostream>
using namespace std;

int main() {

	double tab[6][7] = {	{ 0.53,  4.35, 5.3,  -5.5,  -4.63, 3.62, 4.2 },
							{ 4.2,  -8.23,  -35, 7.13,  -4.62, -34, -4.32 },
							{ 62.3, 63.2, 6, 0.16,  -75, 6.23, 4 },
							{ -53.35, 6.3, 2.63, 4.98,  -3,  -0.97, -8.5 },
							{ -5.3, 5.72, 5.3, 3.85,  5.7, 4, -0.4 },
							{  3.2,  0.35,  -0.95,  8.5, 9.53, 2, 6.4 }};
	int n = 6;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "\t" << tab[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	double* x = new double[n];

	for (int k = 0; k < n; k++) {
		// Wybór elementu g³ównego
		int maxIndex = k;
		for (int i = k + 1; i < n; i++) {
			if (abs(tab[i][k]) > abs(tab[maxIndex][k])) {
				maxIndex = i;
			}
		}

		// Zamiana wierszy
		if (maxIndex != k) {
			for (int j = 0; j <= n; j++) {
				swap(tab[k][j], tab[maxIndex][j]);
			}
		}

		// Eliminacja Gaussa
		for (int i = k + 1; i < n; i++) {
			for (int j = n; j >= 0; j--) {
				tab[i][j] -= tab[k][j] * (tab[i][k] / tab[k][k]);
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		x[i] = tab[i][n];
		for (int j = i + 1; j < n; j++) {
			x[i] -= tab[i][j] * x[j];
		}
		x[i] /= tab[i][i];
	}

	for (int i = 0; i < n; i++) {
		cout << "\tx" << i + 1 << " = " << x[i] << endl;
	}

	return 0;
}
