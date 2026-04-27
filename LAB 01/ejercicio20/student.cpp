#include <iostream>
#include <string>
using namespace std;

// Incluimos la clase base
#include "principal.cpp"

// Clase derivada
class Student : public principal {
public:
    int graduationYear = 2018;

    void study() override {
        cout << "Studying all day long" << endl;
    }
};