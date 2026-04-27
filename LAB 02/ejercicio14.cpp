#include <iostream>
using namespace std;

// Clase genérica
template <typename T>
class GenType {
private:
    T data;
public:
    GenType(T data) { this->data = data; }
    T getData() { return data; }
};

int main() {
    GenType<int> gt(10);
    cout << gt.getData() << endl;
    return 0;
}