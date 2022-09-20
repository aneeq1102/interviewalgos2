// https://leetcode.com/problems/climbing-stairs/submissions/


// dp with array
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        vector<int> dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        
       
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
    }
};

// three variables soln

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        
        int one=1;
        int two=2;
        int three=3;
        
        for(int i=3;i<=n;i++){
            three = one+two;
            one=two;
            two=three;
        }
        
        return three;
    }
};