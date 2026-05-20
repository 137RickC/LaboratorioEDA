#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> pila;

    pila.push("jack");
    pila.push("john");
    pila.push("jacob");

    cout << "Before Pop" << endl;
    // Mostrar pila sin destruir la original
    stack<string> temp = pila;
    while (!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }
    // Eliminar el elemento superior
    pila.pop();
    cout << "\nAfter Pop" << endl;
    // Mostrar pila después del pop
    temp = pila;
    while (!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }
    return 0;
}