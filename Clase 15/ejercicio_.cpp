#include <iostream>
using namespace std;

int main(){
    cout << "Se imprimirán los números y se indicará si son pares:" << endl;
    for (int num = 1; num <= 10; num++){
        cout << "Dado el número: " << num;
        // Verifica si el número es par
        if(num % 2 == 0){
            cout << " es un número par y amamos los números pares";
        }
        cout << endl;
    }
    return 0;
}
