#include <iostream>
using namespace std;

int main(){
    // Se utiliza '_' como variable de bucle (convención para indicar que no se usa fuera del loop)
    for(int _ = 1; _ <= 10; _++){
        cout << "Valor: " << _ << endl;
    }
    cout << "Realizado" << endl;
    return 0;
}
