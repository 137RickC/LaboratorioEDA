#include <iostream>
using namespace std;

// Clase base
class A {
public:
    void print_A() { cout << "Class A" << endl; }
};

// Clases derivadas que heredan de A
class B : public A {
public:
    void print_B() { cout << "Class B" << endl; }
};
class C : public A {
public:
    void print_C() { cout << "Class C" << endl; }
};
class D : public A {
public:
    void print_D() { cout << "Class D" << endl; }
};

int main() {
    B obj_B; obj_B.print_A(); obj_B.print_B(); cout << endl;
    C obj_C; obj_C.print_A(); obj_C.print_C(); cout << endl;
    D obj_D; obj_D.print_A(); obj_D.print_D();
    return 0;
}