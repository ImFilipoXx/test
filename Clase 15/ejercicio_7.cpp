#include <iostream>
using namespace std;

// Función pseudoaleatoria (LCG simple)
int pseudoRandom(){
    static unsigned int semilla = 12345; // semilla fija para este ejemplo
    semilla = (semilla * 1103515245u + 12345u) % 2147483648u;
    return semilla;
}

int main(){
    char respuesta = 's';
    while(respuesta == 's' || respuesta == 'S'){
        cout << "Tire los dados..." << endl;
        // Genera valores entre 1 y 6 usando la función pseudoaleatoria
        int dado1 = (pseudoRandom() % 6) + 1;
        int dado2 = (pseudoRandom() % 6) + 1;
        cout << "Los valores son: " << dado1 << " y " << dado2 << endl;
        cout << "¿Quieres tirar los dados nuevamente? (s/n): ";
        cin >> respuesta;
    }
    return 0;
}
