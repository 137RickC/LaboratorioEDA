#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// Método genérico (template)
template <typename T>
void genericDisplay(T element) {
    cout << typeid(element).name() << " = " << element << endl;
}

int main() {
    genericDisplay(11);
    genericDisplay(string("Texto"));
    genericDisplay(1.0);
    return 0;
}