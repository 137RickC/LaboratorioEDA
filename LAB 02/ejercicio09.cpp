#include <iostream>
#include <string>
using namespace std;

// Clase genérica (template)
template <typename T>
class Test {
private:
    T obj;
public:
    Test(T obj) { this->obj = obj; }
    T getObject() { return obj; }
};

int main() {
    Test<int>    iObj(15);
    cout << iObj.getObject() << endl;

    Test<string> sObj("Ejemplo de clase Generica");
    cout << sObj.getObject() << endl;
    return 0;
}