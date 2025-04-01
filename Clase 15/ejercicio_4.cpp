#include <iostream>
using namespace std;

int main(){
    int numero;
    cout << "Ingrese un número para comparar: ";
    cin >> numero;

    bool completado = true;
    for(int i = 1; i <= 5; i++){
        // Imprime el valor de i
        cout << "i = " << i << endl;
        // Si el valor de i supera el número ingresado, se interrumpe
        if(i > numero){
            completado = false;
            break;
        }
    }
    // Si todas las iteraciones se completaron, se imprime "Hecho"
    if(completado){
        cout << "Hecho" << endl;
    }
    return 0;
}

