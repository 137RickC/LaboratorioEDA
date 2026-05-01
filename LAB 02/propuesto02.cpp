#include <iostream>
using namespace std;

class Figura {
public:
    virtual void dibujar() {  // virtual = permite anulación
        cout << "Dibujando figura genérica" << endl;
    }
    virtual ~Figura() {}
};
class Circulo : public Figura {
public:
    void dibujar() override { // anula el método del padre
        cout << "Dibujando círculo" << endl;
    }
};
class Cuadrado : public Figura {
public:
    void dibujar() override {
        cout << "Dibujando cuadrado" << endl;
    }
};

int main() {
    Figura* f1 = new Circulo();
    Figura* f2 = new Cuadrado();
    f1->dibujar(); // llama Circulo::dibujar()
    f2->dibujar(); // llama Cuadrado::dibujar()
    delete f1; delete f2;
    return 0;
}