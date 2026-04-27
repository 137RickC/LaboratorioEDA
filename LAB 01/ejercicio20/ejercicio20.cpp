#include <iostream>
using namespace std;

// Incluimos Student
#include "Student.cpp"

int main() {
    Student myObj;

    cout << "Name: " << myObj.fname << endl;
    cout << "Age: " << myObj.age << endl;
    cout << "Graduation Year: " << myObj.graduationYear << endl;

    myObj.study(); // método abstracto implementado

    return 0;
}