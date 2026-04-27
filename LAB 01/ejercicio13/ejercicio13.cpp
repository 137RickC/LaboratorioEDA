#include <iostream>
using namespace std;
// Incluimos la clase
#include "Car.cpp"
int main() {
    Car myCar;
    myCar.fullThrottle();
    myCar.speed(200);
    return 0;   
}