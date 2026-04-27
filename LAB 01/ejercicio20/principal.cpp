#include <iostream>
#include <string>
using namespace std;

// Clase abstracta
class principal {
public:
    string fname = "John";
    int age = 24;

    // Método abstracto (virtual puro)
    virtual void study() = 0;
};