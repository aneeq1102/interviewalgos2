// program to generate set of all substrings for a given string

#include<iostream>
#include<vector>
using namespace std;

vector<string> gensubstr(string s){
    vector<string> res;
    string temp;
    int n=s.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            temp += s[j];
            res.push_back(temp);
        }
        temp.clear();
    }

    return res;
}

int main(){


    string str = "hello";
    vector<string> s=  gensubstr(str);

    for(string x:s){
        cout<<x<<" ";
    }


    return 0;
}