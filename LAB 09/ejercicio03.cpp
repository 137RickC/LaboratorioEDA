#include <iostream>
using namespace std;

// Función para imprimir el arreglo
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Función para implementar la prueba cuadrática
void hashing(int table[], int tsize, int arr[], int n)
{
    // Recorrer los elementos a insertar
    for (int i = 0; i < n; i++) {
        // Calcular el valor hash
        int hv = arr[i] % tsize;

        // Si no hay colisión
        if (table[hv] == -1) {
            table[hv] = arr[i];
        }
        else {
            // Resolver colisiones mediante prueba cuadrática
            for (int j = 1; j <= tsize; j++) {
                int t = (hv + j * j) % tsize;

                if (table[t] == -1) {
                    table[t] = arr[i];
                    break;
                }
            }
        }
    }

    printArray(table, tsize);
}

// Programa principal
int main()
{
    int arr[] = {50, 700, 76, 85, 92, 73, 101};

    int n = sizeof(arr) / sizeof(arr[0]);
    int tsize = 11;
    int hash_table[11];

    // Inicializar la tabla con -1
    for (int i = 0; i < tsize; i++) {
        hash_table[i] = -1;
    }

    // Llamada a la función hash
    hashing(hash_table, tsize, arr, n);
    return 0;
}
