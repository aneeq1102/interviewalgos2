// https://leetcode.com/problems/coin-change/submissions/


#include<iostream>
#include<vector>

using namespace std;

    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        
        for(int temp_amt=1;temp_amt<=amount;temp_amt++){
            for(int coin:coins){
                if(temp_amt >= coin){
                    dp[temp_amt] = min(dp[temp_amt],dp[temp_amt - coin]+1);
                }
            }
        }
        
        return dp[amount];
        
        
    }

int main(){


    vector<int> coins = {1};
    int amt = 13;

    cout << coinChange(coins,amt);

    return 0;
}