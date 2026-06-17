#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    // Implementacion de un unordered_set con 5 palabras
    std::unordered_set<std::string> misPalabras = {
        "Estructura", "Datos", "Algoritmos", "Hashing", "Universidad"
    };

    std::cout << "\n--- Ejercicio 3: Elementos de unordered_set ---" << std::endl;
    // Recorremos e imprimimos los elementos
    for (const std::string& palabra : misPalabras) {
        std::cout << "- " << palabra << std::endl;
    }

    return 0;
}