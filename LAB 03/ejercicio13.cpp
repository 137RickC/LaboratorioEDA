#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {10,20,30};

    for(auto it = arr.begin(); it != arr.end(); it++ )
        cout<< *it << " ";
    
    return 0; 
}
