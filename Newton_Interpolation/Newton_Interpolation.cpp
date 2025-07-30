#include <iostream>
#include <fstream>
#include <string> //getline

using namespace std;

int liczba_linii(string nazwa_pliku) {
	int liczbaLinii = 0;
	string line;

	ifstream plik(nazwa_pliku);
	while (getline(plik, line))liczbaLinii++;
	plik.close();

	return liczbaLinii;
}

int main() {
	int liczbaLinii = liczba_linii("metoda2.txt");

	if (liczbaLinii % 2 != 0 && liczbaLinii > 1) {
		cout << "\nLiczba danych sie nie zgadza" << endl;
		return 0;
	}

	ifstream plik("metoda2.txt");
	string* tab = new string[liczbaLinii];
	for (int i = 0; i < liczbaLinii; i++) {
		getline(plik, tab[i]);
	}
	plik.close();


	int ilosc_wartosci_xy = liczbaLinii / 2;

	double* tabx = new double[ilosc_wartosci_xy]; //wartosci x
	double* taby = new double[ilosc_wartosci_xy]; //wartosci y
	tabx[0] = NULL;
	taby[0] = NULL;


	cout << "\nWartosci x oraz y:" << endl;
	for (int i = 0; i < ilosc_wartosci_xy; i++) {
		tabx[i] = stod(tab[2 * i]);
		cout << "x" << i + 1 << " = " << tabx[i];
		taby[i] = stod(tab[2 * i + 1]);
		cout << "; y" << i + 1 << " = " << taby[i];
		cout << endl;
	}

	double* tab1 = new double[ilosc_wartosci_xy]; //wartosci rzêdów
	tab1[0] = NULL;

	double wynik = taby[0]; // Pocz¹tkowa wartoœæ wyniku
	double punkt_x = 13; // Wartoœæ punktu, dla którego obliczamy interpolacjê

	// Obliczanie wartoœci interpolowanej
	for (int i = 0; i < ilosc_wartosci_xy - 1; i++) {
		tab1[i] = (taby[i + 1] - taby[i]) / (tabx[i + 1] - tabx[i]);
	}
	wynik += (tab1[0] * (punkt_x - tabx[0]));

	for (int i = 0; i < ilosc_wartosci_xy - 2; i++) {
		double temp = 1;
		for (int j = 0; j < (ilosc_wartosci_xy - (i + 2)); j++) {
			tab1[j] = (tab1[j + 1] - tab1[j]) / (tabx[j + i + 2] - tabx[j]);
		}
		for (int k = 0; k < i + 2; k++) {
			temp *= (punkt_x - tabx[k]);
		}
		wynik += (tab1[0] * temp);
	}

	//cout << tab1[0] << endl;

	cout << "\nPrzyblizona wartosc funkcji w punkcie x = " << punkt_x << " przy otrzymanym wielomianie wynosi " << wynik << endl;

	delete[] tab;
	delete[] tabx;
	delete[] taby;

	return 0;
}

/*for (int i = 0; i < liczba_wartosci - 2; i++) {
	tab1[i] = (tab1[i + 1] - tab1[i]) / (tabx[i + 2] - tabx[i]);
}
for (int i = 0; i < liczba_wartosci - 3; i++) {
	tab1[i] = (tab1[i + 1] - tab1[i]) / (tabx[i + 3] - tabx[i]);
}
for (int i = 0; i < liczba_wartosci - 4; i++) {
	tab1[i] = (tab1[i + 1] - tab1[i]) / (tabx[i + 4] - tabx[i]);
	cout << tab1[i] << endl;
}*/