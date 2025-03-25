
#include <iostream>
#include <string>
using namespace std;

int main() {
    float costoComida;

    // Pedir el costo de la comida
    cout << "Introduce el costo de la comida: $";
    cin >> costoComida;

    // Calcular el impuesto (10%) y la propina (18%)
    float impuesto = costoComida * 0.10;
    float propina = costoComida * 0.18;

    // Calcular el total
    float total = costoComida + impuesto + propina;

    // Imprimir los resultados
    cout << "Impuesto: $" << impuesto << endl;
    cout << "Propina: $" << propina << endl;
    cout << "Total: $" << total << endl;

// La IA ayudó a estructurar el flujo de cálculos y la impresión de resultados


    return 0;
}
