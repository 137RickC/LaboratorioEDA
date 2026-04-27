#include <iostream>
using namespace std;
namespace Matematicas {
    void mostrar() {
        cout << "Namespace: Matematicas " << endl;
        cout << "PI = 3.1416" << endl;
        cout << "Raiz de 2 = 1.4142" << endl;
    }
}
namespace Texto {
    void mostrar() {
        cout << "Namespace: Texto " << endl;
        cout << "Hola desde el namespace Texto" << endl;
        cout << "Los namespaces evitan conflictos de nombres" << endl;
    }
}

int main() {
    Matematicas::mostrar();  // llama al mostrar() de Matematicas
    cout << endl;
    Texto::mostrar();        // llama al mostrar() de Texto
    
    return 0;
}