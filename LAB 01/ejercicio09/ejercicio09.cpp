#include <iostream>
using namespace std;
// Incluimos la clase
#include "Main.cpp"
int main() {
    Main myObj1; // Objeto 1
    Main myObj2; // Objeto 2
    myObj2.x = 25; // Solo modificamos el segundo objeto
    cout << myObj1.x << endl; // 5
    cout << myObj2.x << endl; // 25
    return 0;
}