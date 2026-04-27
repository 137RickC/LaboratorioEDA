#include <iostream>
using namespace std;
class Vehiculo {
public:
    virtual void iniciar() = 0;
    virtual void detener() = 0;
};
class Auto : public Vehiculo {
public:
    void iniciar() {
        cout << "El auto esta iniciando" << endl;
    }
    void detener() {
        cout << "El auto se ha detenido" << endl;
    }
};
int main() {
    Auto a;
    a.iniciar();
    a.detener();
    return 0;
}