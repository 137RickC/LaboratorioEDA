#include <iostream>
using namespace std;

class Animal {
public:
    void respirar() { cout << "Respirando..." << endl; }
protected:
    void moverse()  { cout << "Moviéndose..."  << endl; }
};
// Herencia PROTECTED: lo público de Animal se vuelve protegido
class Mamifero : protected Animal {
public:
    void accion() {
        respirar(); // accesible dentro de la clase
        moverse();  // era protected, sigue siéndolo
    }
};
// Herencia PRIVATE: todo lo heredado se vuelve privado
class Perro : private Mamifero {
public:
    void ladrar() {
        accion();   // accesible internamente
        cout << "Guau!" << endl;
    }
};
int main() {
    Perro d;
    d.ladrar();
    // d.accion();   // ERROR: accion() es privado en Perro
    // d.respirar(); // ERROR: respirar() es privado en Perro
    return 0;
}