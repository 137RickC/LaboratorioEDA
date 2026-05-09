#include <iostream>
using namespace std;

int main() {
    char* arr = new char[5]{'C','C','H','A','R'};

    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    delete[] arr;
    return 0;
}