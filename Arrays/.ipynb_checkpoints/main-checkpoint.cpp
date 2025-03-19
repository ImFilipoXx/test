#include <iostream>
#include <iomanip> // Include the <iomanip> header to access std::setprecision
#include "TArrayInt.h"

// Excepciones personalizadas
class OutOfRangeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Índice fuera de rango.";
    }
};

class OverflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "El arreglo está lleno. No se puede insertar más elementos.";
    }
};

int main() {
    try {
        // Declaración de un objeto de la clase TArrayInt con tamaño 10
        TArrayInt a(10); 
        
        // Asignar valores al arreglo
        a.SetElement(0, 4);
        a.SetElement(1, 6);
        a.SetElement(2, 3);
        a.SetElement(3, 0);
        a.SetElement(4, 11);
        a.SetElement(5, 0);
        a.SetElement(6, 2);
        a.SetElement(7, 0);
        a.SetElement(8, 2);
        a.SetElement(9, 9);

        // Imprimir longitud y ceros
        std::cout << "¿Qué longitud tiene el array a?: " << a.GetLength() << std::endl;
        std::cout << "¿Cuántos ceros tiene el array a?: " << a.CountZeros() << std::endl;
        std::cout << "¿El array a está lleno?: " << a.IsFull() << std::endl;

        // Intentar insertar un nuevo elemento en el arreglo
        std::cout << "Insertando un nuevo elemento: ";
        try {
            a.InsertLast(6);
            std::cout << "Elemento insertado correctamente." << std::endl;
        } catch (const OverflowException& e) {
            std::cerr << e.what() << std::endl;
        }

        // Imprimir longitud después de la inserción
        std::cout << "Después de la inserción de un último elemento, ¿Qué longitud tiene el array a?: " << a.GetLength() << std::endl;

        // Imprimir los elementos del arreglo
        for (int i = 0; i < a.GetLength(); ++i) {
            std::cout << "Elemento " << i + 1 << " del array a: " << a.GetElement(i) << std::endl;
        }

        // Intentar acceder a un índice fuera de rango
        try {
            std::cout << "Elemento 11 del array a: " << a.GetElement(10) << std::endl;  // Índice fuera de rango
        } catch (const OutOfRangeException& e) {
            std::cerr << e.what() << std::endl;
        }

        // Obtener y mostrar la suma de los elementos
        int suma = a.Sum();
        std::cout << "Suma de los elementos del array a: " << suma << std::endl;

        // Obtener y mostrar el promedio de los elementos
        float c = a.Average();
        std::cout << "Promedio de los elementos del array a: " << std::fixed << std::setprecision(4) << c << std::endl;

        // Crear un objeto TArrayInt con longitud 0 y verificar si está vacío
        TArrayInt b(0);
        std::cout << "¿El array b está vacío?: " << b.IsEmpty() << std::endl;

    } catch (const std::exception& e) {
        // Captura las excepciones generales
        std::cerr << "Error general: " << e.what() << std::endl;
    }

    return 0;
}

