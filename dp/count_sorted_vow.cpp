class Solution {
public:
    int countVowelStrings(int n) {
        array<int,5> dp;
        dp.fill(1);
        for(int i=1;i<=n;i++){
            for(int j=3;j>=0;j--){
                dp[j] += dp[j+1];
            }
        }
        
        return dp[0];
        
        
    }
};

// https://leetcode.com/problems/count-sorted-vowel-strings/submissions/