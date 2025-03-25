
#include <iostream>
#include <string>
using namespace std;

int main() {
    int cantidadWidgets, cantidadGizmos;

    // Pedir las cantidades de widgets y gizmos
    cout << "Introduce la cantidad de widgets: ";
    cin >> cantidadWidgets;

    cout << "Introduce la cantidad de gizmos: ";
    cin >> cantidadGizmos;

    // Cada widget pesa 75 gramos y cada gizmo 112 gramos
    int pesoWidgets = cantidadWidgets * 75;
    int pesoGizmos = cantidadGizmos * 112;

    // Calcular el peso total
    int pesoTotal = pesoWidgets + pesoGizmos;

    cout << "El peso total del pedido es: " << pesoTotal << " gramos." << endl;

 // La IA ayudó a estructurar el cálculo del peso total y la impresión del resultado sin embargo se utilizo conocimientos basicos vistos en clases anteriores

    return 0;
}
