#include <iostream>
#include <string>
using namespace std;
// Intercambio genérico
template <typename T>
void swapValues(T &a, T &b) {
    T temp = a; a = b; b = temp;
}
// Ordenamiento burbuja genérico
template <typename T>
void ordenamiento_generico(T arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swapValues(arr[j], arr[j + 1]);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";
    cout << endl;
}

int main() {
    int    a[] = {100, 22, 58, 41, 6, 50};
    char   c[] = {'v','g','a','c','x','d','t'};
    string s[] = {"Amiya","Kuna","Gudly","Sweta","Mama","Rani","Kandhei"};
    cout << "Arreglo de enteros ordenados: ";
    ordenamiento_generico(a, 6);
    cout << "Arreglo de caracteres ordenados: ";
    ordenamiento_generico(c, 7);
    cout << "Arreglo de cadenas ordenados: ";
    ordenamiento_generico(s, 7);
    return 0;
}