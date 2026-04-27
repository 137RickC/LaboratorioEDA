#include <iostream>
using namespace std;

// Clase base
class Bicycle {
public:
    int gear;
    int speed;

    // Constructor
    Bicycle(int gear, int speed) {
        this->gear = gear;
        this->speed = speed;
    }

    void applyBrake(int decrement) { speed -= decrement; }
    void speedUp(int increment)    { speed += increment; }

    // Método virtual para permitir sobreescritura
    virtual string toString() {
        return "Numero de llantas: " + to_string(gear) +
               "\nla velocidad de la bicicleta es: " + to_string(speed);
    }
};

// Clase derivada
class MountainBike : public Bicycle {
public:
    int seatHeight;

    MountainBike(int gear, int speed, int startHeight)
        : Bicycle(gear, speed) {
        seatHeight = startHeight;
    }

    void setHeight(int newValue) { seatHeight = newValue; }

    // Sobrescritura del método
    string toString() override {
        return Bicycle::toString() +
               "\naltura del asiento es: " + to_string(seatHeight);
    }
};

int main() {
    MountainBike mb(3, 100, 25);
    cout << mb.toString() << endl;
    return 0;
}