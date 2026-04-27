#include <iostream>
using namespace std;
// Incluimos la clase
#include "principal.cpp"
int main() {
    // Llamada al método estático
    principal::myMethod();
    return 0;
}