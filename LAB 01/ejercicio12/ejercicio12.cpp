#include <iostream>
using namespace std;
// Incluimos la clase
#include "principal.cpp"
int main() {
    // Llamada a método estático (sin objeto)
    principal::myStaticMethod();
    // Llamada a método no estático (requiere objeto)
    principal myObj;
    myObj.myPublicMethod();
    return 0;
}