
#include <iostream>
#include <string>
using namespace std;

int main() {
    // La frase original con palabras desordenadas
    string frase = "culpa, mal, un, siempre, la, trabajador, a, herramienta";

    // Reemplazar las comas por espacios
    for (int i = 0; i < frase.length(); i++) {
        if (frase[i] == ',') {
            frase[i] = ' ';
        }
    }

    // Mostrar la frase con un solo espacio entre palabras
    cout << frase << endl;

 // La IA ayudó a estructurar el proceso de reemplazar las comas por espacios

    return 0;
}
