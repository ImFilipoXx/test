
#include <iostream>
#include <string>
using namespace std;

int main() {
    string frase = "culpa, mal, un, siempre, la, trabajador, a, herramienta";

    // Colocar las mayúsculas necesarias y agregar la coma
    frase = "Siempre, la herramienta, mal, un trabajador, a.";

    // Mostrar la frase modificada
    cout << frase << endl;

    // Reemplazar "trabajador" por "estudiante" y "herramienta" por "profesor"
    size_t pos = frase.find("trabajador");
    if (pos != string::npos) {
        frase.replace(pos, 10, "estudiante");
    }

    pos = frase.find("herramienta");
    if (pos != string::npos) {
        frase.replace(pos, 11, "profesor");
    }

    // Mostrar la frase después de las modificaciones
    cout << frase << endl;

    return 0;
}

