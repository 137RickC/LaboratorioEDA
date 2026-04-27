#include <iostream>
using namespace std;
// Clase abstracta
class Animal {
public:
    virtual void dormirSonido() =0; 
    virtual ~Animal() {}
};
// Clase derivada
class Perro : public Animal {
public:
    void dormirSonido() override {
        cout << "Zzz..." << endl;
    }

    void ladrar() {
        cout << "¡Guau!" << endl;
    }
};
int main() {
    Perro miPerro;
    miPerro.dormirSonido();
    miPerro.ladrar();
    return 0;
}