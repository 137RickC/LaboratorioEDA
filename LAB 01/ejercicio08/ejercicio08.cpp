#include <iostream>
using namespace std;
// Incluimos la clase
#include "principal.cpp"
int main() {
    principal myObj;
    //myObj.x = 25; // ERROR: no se puede modificar un atributo const
    cout <<myObj.x <<endl;
    return 0;
}