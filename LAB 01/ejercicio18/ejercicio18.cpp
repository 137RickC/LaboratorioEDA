#include <iostream>
using namespace std;

// Incluimos la clase
#include "principal.cpp"

int main() {
    principal myObj;

    // Las siguientes líneas generarían error:
    // myObj.x = 50;
    // myObj.PI = 25;

    cout << myObj.x << endl;
    cout << myObj.PI << endl;

    return 0;
}