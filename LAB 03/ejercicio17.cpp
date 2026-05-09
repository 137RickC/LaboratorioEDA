#include <iostream>
#include <vector>
using namespace std;

int main (){
    vector<int> arr = {1,2,3};

    arr.resize(5);

    for(int x : arr)
        cout << x << " ";

    return 0;
}