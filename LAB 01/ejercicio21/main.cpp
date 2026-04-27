#include <iostream>
using namespace std;

// Incluimos la clase
#include "Person.cpp"

int main() {
    Person myObj;

    // myObj.name = "John";  // ERROR (privado)

    myObj.setName("John");  // correcto usando setter

    cout << myObj.getName() << endl;  // correcto usando getter

    return 0;
}