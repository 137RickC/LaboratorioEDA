#include <iostream>
using namespace std;
// Importamos la clase
#include "principal.cpp"
int main() {
    principal myCar;
    myCar.fullThrottle();
    myCar.speed(200);
    return 0;
}