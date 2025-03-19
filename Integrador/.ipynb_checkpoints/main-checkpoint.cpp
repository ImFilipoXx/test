#include <iostream>
#include "TSanSilvestre.h"

// Función para manejar los errores de los récords
void TestSanSilvestre() {
    try {
        // Crear un deportista con nombre y deporte
        TDDate fecha;
        fecha.Day = 10;
        fecha.Mounth = 2;
        fecha.Year = 1990;

        TSanSilvestre *deportista = new TSanSilvestre("Juan", "Atletismo");
        deportista->SetBirth(fecha);

        // Imprimir los datos básicos del deportista
        std::cout << "La fecha de nacimiento del deportista es: " << deportista->GetBirth().Day << ", " << deportista->GetBirth().Mounth << ", " << deportista->GetBirth().Year << std::endl;
        std::cout << "El nombre del deportista es: " << deportista->GetName() << std::endl;
        std::cout << "El deporte es: " << deportista->GetDeporte() << std::endl;

        // Establecer los récords
        try {
            deportista->SetRecord(0, 10.0);
            deportista->SetRecord(1, 11.0);
            deportista->SetRecord(2, 12.0);
            deportista->SetRecord(3, 13.0);
            deportista->SetRecord(4, 14.0);
        } catch (const InvalidRecordException& e) {
            std::cerr << "Error al establecer el récord: " << e.what() << std::endl;
        } catch (const OutOfRangeException& e) {
            std::cerr << "Error al establecer el récord: " << e.what() << std::endl;
        }

        // Imprimir los récords
        try {
            std::cout << "El récord 1 es: " << deportista->GetRecord(0) << std::endl;
            std::cout << "El récord 2 es: " << deportista->GetRecord(1) << std::endl;
            std::cout << "El récord 3 es: " << deportista->GetRecord(2) << std::endl;
            std::cout << "El récord 4 es: " << deportista->GetRecord(3) << std::endl;
            std::cout << "El récord 5 es: " << deportista->GetRecord(4) << std::endl;
        } catch (const OutOfRangeException& e) {
            std::cerr << "Error al obtener el récord: " << e.what() << std::endl;
        }

        // Comparar el promedio de los récords con un valor
        std::cout << "¿El promedio es mayor que 30.5? " << deportista->Compare(30.5) << std::endl;

        // Eliminar el objeto dinámicamente creado
        delete deportista;

    } catch (const std::exception& e) {
        // Captura las excepciones generales
        std::cerr << "Error general: " << e.what() << std::endl;
    }
}

int main() {
    TestSanSilvestre();
    return 0;
}


 

