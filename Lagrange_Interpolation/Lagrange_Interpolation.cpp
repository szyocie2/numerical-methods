#include <iostream>
#include <fstream>
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
	int liczbaLinii = liczba_linii("metoda1.txt");

	if ((liczbaLinii-1) % 2 != 0) {
		cout << "\nLiczba danych sie nie zgadza" << endl;
		return 0;
	}

	int liczba_wartosci = (liczbaLinii - 1) / 2;

	ifstream plik("metoda1.txt");
	string* tab = new string[liczbaLinii];
	for (int i = 0; i < liczbaLinii; i++) {
		getline(plik, tab[i]);
	}
	plik.close();

	double punkt_x = stod(tab[0]);
	cout << "Punkt x = " << punkt_x << endl;

	double* tabx = new double[liczba_wartosci]; //wartosci x
	double* taby = new double[liczba_wartosci]; //wartosci y

	for (int i = 0; i < liczba_wartosci; i++) {
		tabx[i] = stod(tab[2 * i + 1]);
		cout << "x" << i + 1 << " = " << tabx[i];
		taby[i] = stod(tab[2 * i + 2]);
		cout << "; y" << i + 1 << " = " << taby[i];
		cout << endl;
	}

	double wynik = 0;

	for (int i = 0; i < liczba_wartosci; i++) {
		double temp = 1;
		for (int j = 0; j < liczba_wartosci; j++) {
			if (j != i) {
				temp *= (punkt_x - tabx[j]) / (tabx[i] - tabx[j]);
			}
		}
		wynik += temp * taby[i];
	}

	cout << "Wartosc interpolacji w punkcie x = " << punkt_x << " wynosi: " << wynik << endl;

	delete[] tab;
	delete[] tabx;
	delete[] taby;

	return 0;
}
