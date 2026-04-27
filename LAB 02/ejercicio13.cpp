#include <iostream>
using namespace std;

// Clase genérica
template <typename T>
class Area {
private:
    T t;
public:
    void add(T t) { this->t = t; }
    T    get()    { return t; }
    void getArea() { /* implementar según figura */ }
};

int main() {
    Area<int>    rectangulo;
    Area<double> circulo;
    rectangulo.add(10);
    circulo.add(2.5);
    cout << rectangulo.get() << endl;
    cout << circulo.get()    << endl;
    return 0;
}