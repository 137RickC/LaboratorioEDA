#include <iostream>
using namespace std;
class principal {
public:
    void myPublicMethod() {
        cout << " Métodos públicos deben ser llamados creando objetos " << endl;
    }
    static void myStaticMethod() {
        cout << " Métodos estáticos pueden ser llamados sin crear objetos " <<endl;
    }
};