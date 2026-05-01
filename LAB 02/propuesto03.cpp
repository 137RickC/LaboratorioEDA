#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
class Arreglo {
private:
    T datos[5];
public:
    // Restricción: solo tipos numéricos (enteros o decimales)
    Arreglo() {
        static_assert(is_arithmetic<T>::value, 
                      "Solo se permiten tipos numericos");
    }
    void llenar() {
        for(int i = 0; i < 5; i++) {
            cout << "Ingrese valor: ";
            cin >> datos[i];
        }
    }
    void mostrar() {
        for(int i = 0; i < 5; i++) {
            cout << datos[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Arreglo<int> a;     // válido
    a.llenar();
    a.mostrar();
    // Arreglo<string> b; // no es tipo numérico
    return 0;
}