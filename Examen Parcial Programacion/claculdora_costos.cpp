#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Renovacion {
private:
    double largo, ancho, alto;
    double metrosNoPintar;
    double costoPorMetro;

public:
    // Constructor
    Renovacion(double l, double a, double h, double noPintar, double costo)
        : largo(l), ancho(a), alto(h), metrosNoPintar(noPintar), costoPorMetro(costo) {}

    // Método para calcular metros cuadrados a pintar
    double calcularArea() {
        double totalMetros = (2 * (largo * alto) + 2 * (ancho * alto));
        return totalMetros - metrosNoPintar;
    }

    // Método para calcular el costo total
    double calcularCosto() {
        return calcularArea() * costoPorMetro;
    }
};

// Función para simular el pago y calcular el cambio
void calcularCambio(double total, double pago) {
    double cambio = pago - total;
    cout << "Cambio: " << cambio << " USD" << endl;

    int centavos = round(cambio * 100);
    int monedas25 = centavos / 25;
    centavos %= 25;
    int monedas10 = centavos / 10;
    centavos %= 10;
    int monedas5 = centavos / 5;
    centavos %= 5;
    int monedas1 = centavos;

    cout << "Desglose del cambio:" << endl;
    cout << "Monedas de 25 centavos: " << monedas25 << endl;
    cout << "Monedas de 10 centavos: " << monedas10 << endl;
    cout << "Monedas de 5 centavos: " << monedas5 << endl;
    cout << "Monedas de 1 centavo: " << monedas1 << endl;
}

int main() {
    double largo, ancho, alto, noPintar, costoPorMetro, pago;

    // Capturamos los datos de la habitación
    cout << "Ingrese las dimensiones de la habitación (largo, ancho, alto en metros): ";
    cin >> largo >> ancho >> alto;

    cout << "Ingrese los metros cuadrados que no se deben pintar (puertas, ventanas, etc.): ";
    cin >> noPintar;

    cout << "Ingrese el costo de la pintura por metro cuadrado: ";
    cin >> costoPorMetro;

    // Creamos un objeto de la clase Renovacion
    Renovacion habitacion(largo, ancho, alto, noPintar, costoPorMetro);

    // Mostramos los resultados
    double costoTotal = habitacion.calcularCosto();
    cout << "El costo total de la pintura es: " << costoTotal << " USD" << endl;

    // Simulación de pago
    cout << "Ingrese la cantidad con la que pagará: ";
    cin >> pago;

    if (pago >= costoTotal) {
        calcularCambio(costoTotal, pago);
    } else {
        cout << "El pago es insuficiente." << endl;
    }

    return 0;
}


