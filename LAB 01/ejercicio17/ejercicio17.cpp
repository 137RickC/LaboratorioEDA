#include <iostream>
#include <string>
using namespace std;

// Incluimos la clase
#include "principal.cpp"

int main() {
    principal myCar(1969, "Mustang");

    cout << myCar.modelYear << " " << myCar.modelName << endl;

    return 0;
}