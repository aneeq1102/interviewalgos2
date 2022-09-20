//  https://leetcode.com/problems/interleaving-string/submissions/

#include<bits/stdc++.h>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.size(),n2=s2.size();
    
    if(n1 + n2 != s3.size()){
        return 0;
    }
    vector<vector<bool>> dp(n1+1,vector<bool>(n2+1,0));    
    dp[n1][n2]=1;
    
    for(int i=n1;i>=0;i--){
        for(int j=n2;j>=0;j--){
            
            if( i<n1 && s1[i]==s3[i+j] && dp[i+1][j] ){
                dp[i][j]=1;
            }
            if( j<n2 && s2[j]==s3[i+j] && dp[i][j+1] ){
                dp[i][j]=1;
            }
            
        }
    }
    
    return dp[0][0];
}

int main(){
    // string s1="aabcc";
    // string s2="dbbca";
    // string s3="aadbbcbcac";
    // cout << isInterleave(s1,s2,s3);
    // return 0;

    
}