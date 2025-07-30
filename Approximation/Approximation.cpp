#include <iostream>
#include <fstream>
#include <cmath>
#include <string> //getline

using namespace std;

int liczba_linii(string nazwa_pliku) {
	int liczbaLinii = 0;
	string line;

	ifstream liczbalinii(nazwa_pliku);
	while (getline(liczbalinii, line))liczbaLinii++;
	liczbalinii.close();

	return liczbaLinii;
}

int main() {
	int liczbaLinii = liczba_linii("metoda3.txt");

	if (liczbaLinii % 2 != 0) {
		cout << "\nLiczba danych sie nie zgadza" << endl;
		return 0;
	}

	ifstream plik("metoda3.txt");
	string* tab = new string[liczbaLinii];
	for (int i = 0; i < liczbaLinii; i++) {
		getline(plik, tab[i]);
	}
	plik.close();


	int n = liczbaLinii / 2;;

	double* tabx = new double[n]; //wartosci x
	double* taby = new double[n]; //wartosci y
	tabx[0] = NULL;
	taby[0] = NULL;

	cout << "\nWartosci x oraz y:" << endl;
	for (int i = 0; i < n; i++) {
		tabx[i] = stod(tab[2 * i]);
		cout << "x" << i + 1 << " = " << tabx[i];
		taby[i] = stod(tab[2 * i + 1]);
		cout << "; y" << i + 1 << " = " << taby[i];
		cout << endl;
	}

	double a0(1), a1(1), r(1);
	double sum(0); //suma iloczynów x[i] * y[i]
	double sumx(0); //suma x-ów
	double sumy(0); //suma y-ów
	double sumx2(0); //suma kwadratów x[i]
	double sumy2(0); ////suma kwadratów y[i]

	for (int i = 0; i < n; i++) {
		sum += tabx[i] * taby[i];
		sumx += tabx[i];
		sumy += taby[i];
		sumx2 += tabx[i] * tabx[i];
		sumy2 += taby[i] * taby[i];
	}

	a1 = ((n * sum) - (sumx * sumy)) / ((n * sumx2) - (sumx * sumx));
	a0 = ((sumy * sumx2) - (sumx * sum)) / ((n * sumx2) - (sumx * sumx));
	r = ((n * sum) - (sumx * sumy)) / (sqrt((n * sumx2) - (sumx * sumx)) * sqrt((n * sumy2) - (sumy * sumy)));

	cout << endl << "a1 = " << a1 << endl;
	cout << "a0 = " << a0 << endl;
	cout << "Wspolczynnik korelacji jest rowny = " << r << endl;

	delete[] tab;
	delete[] tabx;
	delete[] taby;

	return 0;
}
