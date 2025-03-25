#include <iostream>
#include <string>
using namespace std;

int main() {
    float ancho, largo;

    // Pedir el ancho y largo de la habitación
    cout << "Introduce el ancho de la habitación (en metros): ";
    cin >> ancho;

    cout << "Introduce el largo de la habitación (en metros): ";
    cin >> largo;

    // Calcular el área
    float area = ancho * largo;

    cout << "El área de la habitación es: " << area << " metros cuadrados." << endl;

// La IA ayudó a estructurar el cálculo del área y la impresión del resultado con "cout"

    return 0;
}
