#include <string> // Include the header file for the String class
#include <stdexcept> // Para usar las excepciones estándar
#include <iostream>  // Para las operaciones de impresión

/**Implementación de las funciones miembros*/

// Excepciones personalizadas
class OutOfRangeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Índice fuera de rango para los récords.";
    }
};

class InvalidRecordException : public std::exception {
public:
    const char* what() const noexcept override {
        return "El valor del récord no es válido (debe ser positivo).";
    }
};

TSanSilvestre::TSanSilvestre(std::string pName, std::string pDeport) {
    aName = pName;
    aDeport = pDeport;
    for (int i = 0; i < 5; i++) {
        aRecord[i] = 0.0;
    }
    aBirth.Day = 0;
    aBirth.Mounth = 0;
    aBirth.Year = 0;
}

TSanSilvestre::~TSanSilvestre() {}

TDDate TSanSilvestre::GetBirth() {
    TDDate temporal;
    temporal.Day = aBirth.Day;
    temporal.Mounth = aBirth.Mounth;
    temporal.Year = aBirth.Year;
    return temporal;
}

void TSanSilvestre::SetBirth(TDDate pBirth) {
    aBirth.Day = pBirth.Day;
    aBirth.Mounth = pBirth.Mounth;
    aBirth.Year = pBirth.Year;
}

std::string TSanSilvestre::GetName() {
    return aName;
}

std::string TSanSilvestre::GetDeporte() {
    return aDeport;
}

float TSanSilvestre::GetRecord(int pPos) {
    // Control de errores: Verificar que la posición esté dentro del rango
    if (pPos < 0 || pPos >= 5) {
        throw OutOfRangeException();  // Lanzar excepción si el índice está fuera de rango
    }
    return aRecord[pPos];
}

void TSanSilvestre::SetRecord(int pPos, float pValue) {
    // Control de errores: Verificar que la posición esté dentro del rango
    if (pPos < 0 || pPos >= 5) {
        throw OutOfRangeException();  // Lanzar excepción si el índice está fuera de rango
    }
    
    // Control de errores: Verificar que el valor del récord no sea negativo
    if (pValue < 0) {
        throw InvalidRecordException();  // Lanzar excepción si el valor es negativo
    }

    aRecord[pPos] = pValue;
}

bool TSanSilvestre::Compare(float pValue) {
    float sum = 0.0;
    float prom;
    int cont = 0;
    
    for (int i = 0; i < 5; i++) {
        if (aRecord[i] != 0.0) {
            sum += aRecord[i];
            cont++;
        }
    }

    if (cont > 0) {
        prom = sum / cont;
    }

    // Comparar el valor con el promedio de los récords
    if (pValue > prom) {
        return true;
    } else {
        return false;
    }
}

// Función de prueba de control de errores
void TestSanSilvestre() {
    try {
        TSanSilvestre runner("Juan Pérez", "Carrera");

        // Establecer algunos récords
        try {
            runner.SetRecord(0, 12.5f);
            runner.SetRecord(1, 15.3f);
            runner.SetRecord(2, 11.7f);
            runner.SetRecord(3, 16.0f);
            runner.SetRecord(4, 14.2f);
        } catch (const InvalidRecordException& e) {
            std::cerr << "Error al establecer el récord: " << e.what() << std::endl;
        } catch (const OutOfRangeException& e) {
            std::cerr << "Error al establecer el récord: " << e.what() << std::endl;
        }

        // Imprimir algunos récords
        try {
            std::cout << "Récord en la posición 1: " << runner.GetRecord(1) << " minutos" << std::endl;
            std::cout << "Récord en la posición 4: " << runner.GetRecord(4) << " minutos" << std::endl;
        } catch (const OutOfRangeException& e) {
            std::cerr << "Error al obtener el récord: " << e.what() << std::endl;
        }

        // Intentar establecer un valor negativo como récord
        try {
            runner.SetRecord(2, -10.5f);  // Esto lanzará una excepción
        } catch (const InvalidRecordException& e) {
            std::cerr << "Error al establecer el récord: " << e.what() << std::endl;
        }

        // Intentar acceder a un índice fuera de rango
        try {
            std::cout << "Récord en la posición 6: " << runner.GetRecord(6) << " minutos" << std::endl;  // Esto lanzará una excepción
        } catch (const OutOfRangeException& e) {
            std::cerr << "Error al obtener el récord: " << e.what() << std::endl;
        }

        // Comparar si el valor 13.0 es mejor que algún récord
        if (runner.Compare(13.0f)) {
            std::cout << "¡Hay un récord mejor que 13.0 minutos!" << std::endl;
        } else {
            std::cout << "No hay ningún récord mejor que 13.0 minutos." << std::endl;
        }

    } catch (const std::exception& e) {
        // Captura cualquier excepción general
        std::cerr << "Error general: " << e.what() << std::endl;
    }
}

int main() {
    TestSanSilvestre();
    return 0;
}


 