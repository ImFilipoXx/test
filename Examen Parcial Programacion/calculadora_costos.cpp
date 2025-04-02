
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
    // este va a ser el constructor para inicializar los valores
    Renovacion(double l, double a, double h, double noPintar, double costo)
        : largo(l), ancho(a), alto(h), metrosNoPintar(noPintar), costoPorMetro(costo) {}

    // este sera el metodo que calcula la cantidad de metros cuadrados a pintar
    double calcularArea() {
        double totalMetros = (2 * (largo * alto) + 2 * (ancho * alto)); // Calcula las 4 paredes
        double areaFinal = totalMetros - metrosNoPintar; // Restamos lo que no se pinta
        return max(0.0, areaFinal); // Evita valores negativos
    }

    // aca esta el metodo que calcula el costo total de la pintura
    double calcularCosto() {
        return max(0.0, calcularArea() * costoPorMetro); // Evita valores negativos
    }
};

// se creara una funcion para calcular el cambio y desglosarlo en monedas
void calcularCambio(double total, double pago) {
    double cambio = pago - total;
    cout << "Cambio: " << cambio << " EUR" << endl;

    int centavos = round(cambio * 100); // vamos a coonvertimos el cambio a centavos
    int monedas25 = centavos / 25;
    centavos %= 25;
    int monedas10 = centavos / 10;
    centavos %= 10;
    int monedas5 = centavos / 5;
    centavos %= 5;
    int monedas1 = centavos;

    cout << "Desglose del cambio:" << endl;
    cout << "Monedas de 25 centimos: " << monedas25 << endl;
    cout << "Monedas de 10 centimos: " << monedas10 << endl;
    cout << "Monedas de 5 centimos: " << monedas5 << endl;
    cout << "Monedas de 1 centimo: " << monedas1 << endl;
}

int main() {
    double largo, ancho, alto, noPintar = 0, costoPorMetro, pago;
    char respuesta;
    int cantidad;
    double area;

    // le vamos a pedir al usuario los datos de la habitación por separado
    cout << "Ingrese el largo de la habitación en metros: ";
    cin >> largo;
    cout << "Ingrese el ancho de la habitación en metros: ";
    cin >> ancho;
    cout << "Ingrese el alto de la habitación en metros: ";
    cin >> alto;

    // Preguntamos por si existen ventanas
    cout << "¿Hay ventanas? (s/n): ";
    cin >> respuesta;
    if (respuesta == 's' || respuesta == 'S') {
        cout << "¿Cuántas ventanas hay?: ";
        cin >> cantidad;
        for (int i = 0; i < cantidad; i++) {
            cout << "Ingrese el área de la ventana " << i + 1 << " en metros cuadrados: ";
            cin >> area;
            noPintar += area;
        }
    }

    // Preguntamos por puertas
    cout << "¿Hay puertas? (s/n): ";
    cin >> respuesta;
    if (respuesta == 's' || respuesta == 'S') {
        cout << "¿Cuántas puertas hay?: ";
        cin >> cantidad;
        for (int i = 0; i < cantidad; i++) {
            cout << "Ingrese el área de la puerta " << i + 1 << " en metros cuadrados: ";
            cin >> area;
            noPintar += area;
        }
    }

    cout << "Ingrese el costo de la pintura por metro cuadrado en EUR: ";
    cin >> costoPorMetro;

    // Creamos un objeto de la clase Renovacion con los datos ingresados
    Renovacion habitacion(largo, ancho, alto, noPintar, costoPorMetro);

    // Calculamos el costo total
    double costoTotal = habitacion.calcularCosto();
    cout << "El costo total de la pintura es: " << costoTotal << " EUR" << endl;

    // Pedimos el monto con el que se va a pagar
    cout << "Ingrese la cantidad con la que pagará en EUR: ";
    cin >> pago;

    // Verificamos si el pago es suficiente y calculamos el cambio
    if (pago >= costoTotal) {
        calcularCambio(costoTotal, pago);
    } else {
        cout << "El pago es insuficiente." << endl;
    }

    return 0;
}
