#include <iostream>
#include <cmath>
using namespace std;

#define M_PI 3.14159265358979323846
#define M_E 2.71828182845904523536

double f(double x) {
    return pow(M_E, pow(x, 2))/ log(x+2);
}

void  z³oty_podzia³(double a, double b) {
    double epsi = 1e-5;
    double phi = ((1 + sqrt(5)) / 2) - 1; // Z³oty podzia³

    double c = b - phi * (b - a);
    double d = a + phi * (b - a);

    while (b - a >= epsi) {
        if (f(c) < f(d)) {
            b = d;
        }
        else {
            a = c;
        }

        // Obliczamy nowe c i d
        c = b - phi * (b - a);
        d = a + phi * (b - a);
    }

    cout << "\n\tMinimum funkcji wynosi: " << (b + a) / 2 << endl;
}

int main() {
    double a = 0.1;
    double b = 1.6;

    z³oty_podzia³(a, b);

    return 0;
}