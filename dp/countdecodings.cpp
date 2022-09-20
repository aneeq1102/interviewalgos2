
// https://leetcode.com/problems/decode-ways/submissions/

#include<iostream>
using namespace std;

/*

Recursive solution 

class Solution {
public:
    int helper(string s,int ind){
        
        int n = s.size();
        
        if(ind == n){
            return 1;
        }
        
        if(s[ind] == '0'){
            return 0;
        }
        
        int res = helper(s,ind+1);
        
        if(ind < n-1 && (s[ind] == '1' || (s[ind] == '2' && s[ind+1] <= '6'))){
            res += helper(s,ind +2);
        }
        
        return res;
        
    }
    int numDecodings(string s) {
        if(s.empty()){
            return 0;
        }
        return helper(s,0);
    }
};

*/

// dynamic programing solution
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        vector<int> dp(n+1,0);
        dp[n] = 1;
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == '0'){
                dp[i] = 0;
            }else{
                dp[i] = dp[i+1];
                
                if(i < n-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))){
                    dp[i] += dp[i+2];
                }
            }
        }
        
        return dp[0];
    }
};


int main(){

    cout << numDecodings("226");

    return 0;
}