#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<double> arr = {1.5, 2.5, 3.5};

    for (double x : arr)
        cout << x <<" ";
        
    return 0;
}