
#include <iostream>
using namespace std;

int main() {
    // Declaramos una variable para almacenar el nombre del usuario
    string nombre;

    // Pedimos al usuario que ingrese su nombre
    cout << "Por favor, ingresa tu nombre: ";
    cin >> nombre;

    // Imprimimos un saludo usando el nombre que nos dio el usuario
    cout << "¡Hola, " << nombre << "!" << endl;

    return 0;
}
