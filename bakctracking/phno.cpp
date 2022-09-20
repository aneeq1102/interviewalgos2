#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v1={2,3,4,5};
    vector<int> v2 = {6,6,7,8};

    v1.swap(v2);

    for(int x:v1){
        cout<<x;
    }
    cout << endl;
    for(int x:v2){
        cout << x;
    }


    return 0;
}