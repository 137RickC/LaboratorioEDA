#include <iostream>
using namespace std;

int main(){
    int* arr = new int[5]{3,7,2,9,1};
    int max = arr[0];

    for (int i = 0; i < 5; i++)
        if (arr[i] >max)
            max = arr[i];
    cout << "Mayor: "<< max;
    delete[] arr;
    return 0;
}