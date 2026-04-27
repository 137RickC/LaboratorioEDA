#include <iostream>
using namespace std;
// Incluimos la clase
#include "principal.cpp"
int main() {
    principal myObj;
    cout << "Name: " <<myObj.fname << " " << myObj.lname << endl;
    cout << "Age: "<<myObj.age << endl;
    return 0;
}