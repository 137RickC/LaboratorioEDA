#include <iostream>
using namespace std;
int main(){
    int* arr = new int[2]{4, 10};
    cout << arr[0] << " " << arr[1];
    
    delete[] arr;
    arr = nullptr;

    return 0;
}