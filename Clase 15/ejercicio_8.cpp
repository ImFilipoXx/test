#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int PENNIES_PER_NICKEL = 5;
const double NICKEL = 0.05;

class Ejercicio9 {
public:
    void ejecutar() {
        double total;
        cout << "Ingrese el total de la compra: ";
        cin >> total;

        int centavos = total * 100;  
        int redondeado = (centavos + PENNIES_PER_NICKEL / 2) / PENNIES_PER_NICKEL * PENNIES_PER_NICKEL;
        double totalRedondeado = redondeado / 100.0;

        cout << fixed << setprecision(2);
        cout << "Total redondeado: $" << totalRedondeado << endl;
    }
};

int main() {

    return 0;
}
