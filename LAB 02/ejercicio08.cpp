#include <iostream>
using namespace std;
// Clase base
class Padre {
public:
    virtual void Print() {
        cout << "Clase padre" << endl;
    }
    virtual ~Padre() { }
};

// Subclase 1
class Subclase1 : public Padre {
public:
    void Print() override { cout << "subclase1" << endl; }
};
// Subclase 2
class Subclase2 : public Padre {
public:
    void Print() override { cout << "subclase2" << endl; }
};

int main() {
    Padre* a = new Subclase1();
    a->Print();
    delete a;
    a = new Subclase2();
    a->Print();
    delete a;
    return 0;
}