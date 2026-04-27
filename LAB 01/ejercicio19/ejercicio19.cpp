#include <iostream>
using namespace std;

// Incluimos la clase
#include "principal.cpp"

class second {
public:
    static void myStaticMethod() {
        cout << "Métodos estáticos pueden ser llamados sin crear objetos" << endl;
    }
};

int main() {
    // Llamada a método estático (sin objeto)
    second::myStaticMethod();

    // Llamada a método no estático (requiere objeto)
    principal myObj;
    myObj.myPublicMethod();

    return 0;
}