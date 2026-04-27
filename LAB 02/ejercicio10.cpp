#include <iostream>
#include <string>
using namespace std;
// Clase genérica con dos tipos
template <typename T, typename U>
class Test {
private:
    T objeto1;
    U objeto2;
public:
    Test(T objeto1, U objeto2) {
        this->objeto1 = objeto1;
        this->objeto2 = objeto2;
    }
    void print() {
        cout << objeto1 << endl;
        cout << objeto2 << endl;
    }
};

int main() {
    Test<string, int> obj("Texto", 15);
    obj.print();
    return 0;
}