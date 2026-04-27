#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;

public:
    // Getter
    string getName() {
        return name;
    }

    // Setter
    void setName(string newName) {
        name = newName;
    }
};