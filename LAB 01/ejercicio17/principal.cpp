#include <iostream>
#include <string>
using namespace std;

class principal {
public:
    int modelYear;
    string modelName;

    // Constructor con dos parámetros
    principal(int year, string name) {
        modelYear = year;
        modelName = name;
    }
};