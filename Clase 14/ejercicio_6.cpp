
#include <iostream>
#include <string>
using namespace std;

int main() {
    float ancho, largo;

    // Pedir el ancho y largo en pies
    cout << "Introduce el ancho del campo (pies): ";
    cin >> ancho;

    cout << "Introduce el largo del campo (pies): ";
    cin >> largo;

    // Calcular el área en pies cuadrados
    float areaEnPies = ancho * largo;

    // Convertir pies cuadrados a acres (1 acre = 43,560 pies cuadrados)
    float areaEnAcres = areaEnPies / 43560;

    cout << "El área del campo es: " << areaEnAcres << " acres." << endl;

    return 0;
}
