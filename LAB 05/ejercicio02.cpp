#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector <int> s;
    // Poniendo elementos
    s.push_back(10);
    s.push_back(20);
    s.push_back(30);
    
    // Sacando e imprimiendo el elemento de la cima
    cout << s.back() << " sacado de la pila" << endl;
    s.pop_back();

    // Observar el elemento en la cima
    cout << "El elemento en la cima es: "<< s.back() << endl;
    // Imprimir todos los elementos en la pila
    cout << "Elementos presentes en la pila: ";
    while (!s.empty()) {
        cout << s.back() << " "; 
        s.pop_back();
    }
    return 0;
}