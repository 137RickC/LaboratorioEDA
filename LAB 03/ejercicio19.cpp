#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr;
    for (int i = 0; i < 5; i++)
        arr.push_back(i *2);

    for(int x :arr )
        cout << x <<" ";
    return 0;
    
}