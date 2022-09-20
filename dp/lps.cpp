//  https://leetcode.com/problems/longest-palindromic-substring/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestPalindrome(string s) {
    int n=s.size();
    
    vector<vector<int>> dp(n,vector<int>(n,0));
    
    for(int i=0;i<n;i++){
        dp[i][i]=1;
        
    }

    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
        }else{
            dp[i][i+1]=0;
        }
    }

    int max_count=0;
    int ml=0,mr=0;
    for(int i=2;i<n-1;i++){
        for(int j=0;j<n;j++){
            if(s[i]==s[j] && dp[i+1][j-1]==1 && j+i<n){
                dp[j][j+i];
                if(max_count < j-i+1){
                    max_count=j-i+1;
                    ml=i;
                    mr=j;
                }
            }
        }
    }
    return s.substr(ml,mr-ml+1);
    
}

int main(){


    string res = longestPalindrome("babad");

    cout << res;

    return 0;
}