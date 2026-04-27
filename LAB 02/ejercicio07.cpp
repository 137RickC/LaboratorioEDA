#include <iostream>
using namespace std;

class Ayudador {
public:
    // Versión con enteros
    static int multiplica(int a, int b) { return a * b; }

    // Versión con decimales
    static double multiplica(double a, double b) { return a * b; }
};

int main() {
    cout << Ayudador::multiplica(2, 4)     << endl;
    cout << Ayudador::multiplica(5.5, 6.3) << endl;
    return 0;
}