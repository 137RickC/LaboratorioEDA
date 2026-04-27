#include <iostream>
using namespace std;
// Incluimos la clase
#include "principal.cpp"
int main() {
    principal myObj(5); // se pasa el valor al constructor
    cout << myObj.x << endl;
    return 0;
}