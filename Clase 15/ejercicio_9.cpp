#include <iostream>
using namespace std;

class Ejercicio10 {
public:
    void ejecutar() {
        int num, factorial = 1;
        cout << "Ingrese un número para calcular su factorial: ";
        cin >> num;

        for (int i = 1; i <= num; i++) {
            factorial *= i;
        }

        cout << "El factorial de " << num << " es: " << factorial << endl;
    }
};

int main() {
    return 0;
}
