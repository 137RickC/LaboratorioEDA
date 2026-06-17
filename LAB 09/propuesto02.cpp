#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // Para std::max

int distanciaMaxima(const std::vector<int>& arr) {
    // Llave: elemento, Valor: primer indice de aparicion
    std::unordered_map<int, int> primeraAparicion;
    int maxDistancia = -1;

    for (int i = 0; i < arr.size(); i++) {
        int elemento = arr[i];

        // Si el elemento no se ha visto antes, guardamos su primera posicion
        if (primeraAparicion.find(elemento) == primeraAparicion.end()) {
            primeraAparicion[elemento] = i;
        } else {
            // Si ya existe, calculamos la distancia con su primera ocurrencia
            int distanciaActual = i - primeraAparicion[elemento];
            maxDistancia = std::max(maxDistancia, distanciaActual);
        }
    }
    
    return maxDistancia;
}

int main() {
    // Ejemplo: El '3' aparece en la pos 1 y pos 6 (distancia = 5)
    // El '2' aparece en la pos 2 y pos 5 (distancia = 3)
    std::vector<int> arr = {1, 3, 2, 4, 5, 2, 3, 8};

    int resultado = distanciaMaxima(arr);
    
    if (resultado != -1) {
        std::cout << "La distancia maxima entre dos ocurrencias es: " << resultado << std::endl;
    } else {
        std::cout << "No hay elementos duplicados en el arreglo." << std::endl;
    }

    return 0;
}