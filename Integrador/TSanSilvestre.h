#include <iostream>
#include <string> // Include the header file for the String class
#include <stdexcept> // Para lanzar excepciones estándar

// Definición de la estructura TDDate
struct TSDate {
    int Day;
    int Mounth;
    int Year;
};
typedef struct TSDate TDDate;

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

// Definición de la clase TSanSilvestre
class TSanSilvestre {
private:
    std::string aName;        // Nombre del participante
    TDDate aBirth;            // Fecha de nacimiento
    std::string aDeport;      // Deporte del participante
    float aRecord[5];         // Array para almacenar los récords

public:
    // Constructor
    TSanSilvestre(std::string pName = "", std::string pDeport = "")
        : aName(pName), aDeport(pDeport) {
        // Inicializar los récords a 0
        for (int i = 0; i < 5; ++i) {
            aRecord[i] = 0.0f;
        }
    }

    // Destructor
    ~TSanSilvestre() {}

    // Métodos para obtener y establecer los datos
    TDDate GetBirth() {
        return aBirth;
    }

    void SetBirth(TDDate pBirth) {
        aBirth = pBirth;
    }

    std::string GetName() {
        return aName;
    }

    std::string GetDeporte() {
        return aDeport;
    }

    void SetRecord(int pPos, float pValue) {
        // Control de errores para la posición del récord
        if (pPos < 0 || pPos >= 5) {
            throw OutOfRangeException();  // Lanzar excepción si el índice está fuera de rango
        }

        // Control de errores para valores negativos en los récords
        if (pValue < 0) {
            throw InvalidRecordException();  // Lanzar excepción si el valor es negativo
        }

        aRecord[pPos] = pValue;  // Asignar el valor al arreglo de récords
    }

    float GetRecord(int pPos) {
        // Control de errores para la posición del récord
        if (pPos < 0 || pPos >= 5) {
            throw OutOfRangeException();  // Lanzar excepción si el índice está fuera de rango
        }

        return aRecord[pPos];  // Retornar el valor del récord
    }

    bool Compare(float pValue) {
        // Comparar el valor con el mejor récord
        for (int i = 0; i < 5; ++i) {
            if (aRecord[i] < pValue) {
                return true;  // Si el valor es mejor que algún récord, retorna true
            }
        }
        return false;  // Si no se encuentra un récord mejor, retorna false
    }
};

int main() {
    try {
        // Crear un objeto de TSanSilvestre
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

    return 0;
}
