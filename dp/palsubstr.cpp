#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int l=0,r=s.size()-1;
    while(l<r){
        if(s[l] != s[r]){
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}
void helper(int ind,int n,vector<vector<string>>& res,vector<string>& part,string s){
    if(ind >=n){
        res.push_back(part);
        return;
    }
    for(int j=ind;j<n;j++){
        string temp = s.substr(ind,j-ind+1);
        if(isPalindrome(temp)){
            part.push_back(s.substr(ind,j-ind+1));
            helper(j+1,n,res,part,s);
            part.pop_back();
        }
    }
}


vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> part;
    helper(0,s.size(),res,part,s);
    
    return res;
}

int main(){

    vector<vector<string>> res = partition("aab");

    for(auto x:res){
        for(auto y:x){
            cout << y << '\t';
        }
    }

    return 0;
}