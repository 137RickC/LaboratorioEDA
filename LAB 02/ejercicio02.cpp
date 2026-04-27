#include <iostream>
using namespace std;

// Clase base
class Empleado {
public:
    int salario = 60000;
};

// Clase derivada
class Ingeniero : public Empleado {
public:
    int beneficios = 10000;
};

int main() {
    Ingeniero E1;
    cout << "Salario : "    << E1.salario    << endl;
    cout << "Beneficios : " << E1.beneficios << endl;
    return 0;
}