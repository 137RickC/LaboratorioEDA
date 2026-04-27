#include <iostream>
#include <string>
using namespace std;
// Clase genérica
template <typename T>
class GenType {
private:
    T data;
public:
    GenType() { }
    GenType(T data) { this->data = data; }
    T getData() { return data; }
    /*
      En C++ NO se puede hacer static T data; dentro de una clase
      template de forma equivalente a Java, ya que cada instancia
      de tipo T genera su propia clase independiente.
    */
};

int main() {
    GenType<string> gt("Metodo generico");
    cout << gt.getData() << endl;
    return 0;
}