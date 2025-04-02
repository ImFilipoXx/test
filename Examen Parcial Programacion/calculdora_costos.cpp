
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Renovacion {
private:
    double largo, ancho, alto; // Dimensiones de la habitación
    double metrosNoPintar; // Área que no se debe pintar (puertas, ventanas, etc.)
    double costoPorMetro; // Precio de la pintura por metro cuadrado

public:
    // Constructor que usare para inicializar los valores
    Renovacion(double l, double a, double h, double noPintar, double costo)
        : largo(l), ancho(a), alto(h), metrosNoPintar(noPintar), costoPorMetro(costo) {}

    // meetodo que calculara la cantidad de metros cuadrados que se van a pintar
    double calcularArea() {
        double totalMetros = (2 * (largo * alto) + 2 * (ancho * alto)); // Calcula las 4 paredes
        return totalMetros - metrosNoPintar; // Restamos lo que no se pinta
    }

    // metodo que calcula el costo total de la pintura
    double calcularCosto() {
        return calcularArea() * costoPorMetro;
    }
};

// funcion que va a calcular el cambio y desglosarlo en monedas
void calcularCambio(double total, double pago) {
    double cambio = pago - total;
    cout << "Cambio: " << cambio << " USD" << endl;

    int centavos = round(cambio * 100); // se convierte primero el cambio a centavos
    int monedas25 = centavos / 25; // aca se calcula cuantas monedas de 25 centavos
    centavos %= 25; // actualizamos los centavos restantes
    int monedas10 = centavos / 10; // ahora calculara las monedas de 10 centavos
    centavos %= 10;
    int monedas5 = centavos / 5; // esto calcula las monedas de 5 centavos
    centavos %= 5;
    int monedas1 = centavos; // lo que va a quedar son de 1 centavo

    cout << "Desglose del cambio:" << endl;
    cout << "Monedas de 25 centavos: " << monedas25 << endl;
    cout << "Monedas de 10 centavos: " << monedas10 << endl;
    cout << "Monedas de 5 centavos: " << monedas5 << endl;
    cout << "Monedas de 1 centavo: " << monedas1 << endl;
}

int main() {
    double largo, ancho, alto, noPintar, costoPorMetro, pago;

    // aca se pedira a la persona que use mi programa que de los datos de la habitación
    cout << "Ingresa las dimensiones de la habitación (largo, ancho, alto en metros): ";
    cin >> largo >> ancho >> alto;

    cout << "ingresa los metros cuadrados que no se deben pintar (puertas, ventanas, etc.): ";
    cin >> noPintar;

    cout << "Ingresa el costo de la pintura por metro cuadrado: ";
    cin >> costoPorMetro;

    // ahora toca crear un objeto de la clase Renovacion con los datos ingresados
    Renovacion habitacion(largo, ancho, alto, noPintar, costoPorMetro);

    // aca calculamos el costo total
    double costoTotal = habitacion.calcularCosto();
    cout << "El costo total de la  que se usara pintura es: " << costoTotal << " EUROS" << endl;

    // pedimos el dinero con el que se va a pagar
    cout << "Ingresa la cantidad con la que pagaras: ";
    cin >> pago;

    // ahora verificamos si el pago es suficiente y calculamos el cambio
    if (pago >= costoTotal) {
        calcularCambio(costoTotal, pago);
    } else {
        cout << "El pago no es exacto. Falta mas dinero." << endl;
    }

    return 0;
}
