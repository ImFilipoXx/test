#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double lluvia[6], total = 0, maxLluvia = 0;

    cout << "Ingrese la cantidad de lluvia caída en cada mes del semestre:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Mes " << (i + 1) << ": ";
        cin >> lluvia[i];
        total += lluvia[i];
        if (lluvia[i] > maxLluvia) {
            maxLluvia = lluvia[i];
        }
    }

    double promedio = total / 6;

    cout << "Promedio de lluvia mensual: " << promedio << " mm" << endl;
    cout << "Mayor cantidad de lluvia en un mes: " << maxLluvia << " mm" << endl;

    return 0;
}
