#include <iostream>
#include <unordered_map>
using namespace std;

// Función para crear el HashMap de frecuencias
void createHashMap(int arr[], int n) {
    // Crear un HashMap vacío (equivalente en C++)
    unordered_map<int, int> hmap;
    // Recorrer el arreglo
    for (int i = 0; i < n; i++) {

        // Si el elemento no existe aún, se inicializa en 0
        if (hmap.find(arr[i]) == hmap.end()) {
            hmap[arr[i]] = 1;
        }
        // Si ya existe, incrementar frecuencia
        else {
            hmap[arr[i]]++;
        }
    }
    // Imprimir el HashMap
    cout << "{ ";

    for (auto it = hmap.begin(); it != hmap.end(); ++it) {
        cout << it->first << "=" << it->second << " ";
    }
    cout << "}" << endl;
}
int main() {
    int arr[] = {10, 34, 5, 10, 3, 5, 10};

    int n = sizeof(arr) / sizeof(arr[0]);

    createHashMap(arr, n);
    return 0;
}
