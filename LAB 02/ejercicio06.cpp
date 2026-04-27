#include <iostream>
using namespace std;

// Clase base
class Persona {
public:
    // Método virtual para permitir polimorfismo
    virtual void rol() {
        cout << "Yo soy una persona." << endl;
    }
    virtual ~Persona() { }
};

// Clase derivada
class Padre : public Persona {
public:
    void rol() override {
        cout << "Yo soy un padre." << endl;
    }
};

int main() {
    // Puntero de tipo base apuntando a objeto derivado
    Persona* p = new Padre();
    p->rol();          // llamada polimórfica
    delete p;
    return 0;
}