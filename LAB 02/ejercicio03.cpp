#include <iostream>
using namespace std;

// Clase base
class Uno {
public:
    void print_principal() { cout << "Principal" << endl; }
};

// Clase derivada
class Dos : public Uno {
public:
    void print_descendiente() { cout << "Descendiente" << endl; }
};

int main() {
    Dos g;
    g.print_principal();
    g.print_descendiente();
    g.print_principal();
    return 0;
}