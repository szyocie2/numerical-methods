#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double punkt[2] = { 0 };
    punkt[0] = 0.5773502692;
    punkt[1] = -0.5773502692;

    double x[4] = { 103.232, 93.643, 13.313, 151.352 };
    double y[4] = { 13.321, 43.233, 212.123, 173.023 };

    double poch_ksi[2][4] = { 0 };
    double poch_ni[2][4] = { 0 };
    double x_ksi, y_ksi, x_ni, y_ni;

    for (int i = 0; i < 2; i++) {
        poch_ksi[i][0] = -.25 * (1.0 - punkt[i]);
        poch_ksi[i][1] = .25 * (1.0 - punkt[i]);
        poch_ksi[i][2] = .25 * (1.0 + punkt[i]);
        poch_ksi[i][3] = -.25 * (1.0 + punkt[i]);

        poch_ni[i][0] = -.25 * (1.0 - punkt[i]);
        poch_ni[i][1] = -.25 * (1.0 + punkt[i]);
        poch_ni[i][2] = .25 * (1.0 + punkt[i]);
        poch_ni[i][3] = .25 * (1.0 - punkt[i]);
    }

    double detJ[2][2] = { 0 };
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            x_ksi = poch_ksi[j][0] * x[0] + poch_ksi[j][1] * x[1] + poch_ksi[j][2] * x[2] + poch_ksi[j][3] * x[3];
            y_ksi = poch_ksi[j][0] * y[0] + poch_ksi[j][1] * y[1] + poch_ksi[j][2] * y[2] + poch_ksi[j][3] * y[3];
            x_ni = poch_ni[i][0] * x[0] + poch_ni[i][1] * x[1] + poch_ni[i][2] * x[2] + poch_ni[i][3] * x[3];
            y_ni = poch_ni[i][0] * y[0] + poch_ni[i][1] * y[1] + poch_ni[i][2] * y[2] + poch_ni[i][3] * y[3];
            detJ[i][j] = x_ksi * y_ni - x_ni * y_ksi;
        }
    }

    double powierzchnia = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            powierzchnia += fabs(detJ[i][j]);
        }
    }

    cout << "Powierzchnia = " << powierzchnia << endl;

    return 0;
}
