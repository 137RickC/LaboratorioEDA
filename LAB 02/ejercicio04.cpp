#include <iostream>
using namespace std;

// Clase base
class Uno {
public:
    void print_principal() { cout << "Principal" << endl; }
};

// Clase intermedia que hereda de Uno
class Dos : public Uno {
public:
    void print_herencia1nivel() { cout << "herencia1nivel" << endl; }
};

// Clase derivada que hereda de Dos
class Tres : public Dos {
public:
    void print_herencia2nivel() { cout << "herencia2nivel" << endl; }
};

int main() {
    Tres g;
    g.print_principal();
    g.print_herencia1nivel();
    g.print_herencia2nivel();
    return 0;
}