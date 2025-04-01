#include <iostream>
#include <string>
using namespace std;

int main() {
    string codigo;
    double costoProduccion;
    int produccion[6], totalProduccion = 0;

    cout << "Ingrese el código de la pieza: ";
    cin >> codigo;

    cout << "Ingrese el costo de producción: ";
    cin >> costoProduccion;

    cout << "Ingrese la producción diaria durante 6 días laborales:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Día " << (i + 1) << ": ";
        cin >> produccion[i];
        totalProduccion += produccion[i];
    }

    cout << "Código de pieza: " << codigo << endl;
    cout << "Costo de producción: " << costoProduccion << " USD" << endl;
    cout << "Producción total en la semana: " << totalProduccion << " unidades" << endl;

    return 0;
}
