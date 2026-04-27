#include <iostream>
using namespace std;
class Auto {
private:
    string modelo;
    int anio;
public:
    // Constructor sin argumentos (por defecto)
    Auto() {
        modelo = "Desconocido";
        anio = 0;
    }
    // Constructor parametrizado
    Auto(string m, int a) {
        modelo = m;
        anio = a;
    }
    void mostrar() {
        cout << "Modelo: " << modelo << " | Año: " << anio << endl;
    }
};

int main() {
    Auto auto1;                      
    Auto auto2("Toyota Corolla", 2022); // constructor parametrizado

    cout << "--- Auto 1 ---" << endl;
    auto1.mostrar();

    cout << "--- Auto 2 ---" << endl;
    auto2.mostrar();

    return 0;
}