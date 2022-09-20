//  https://leetcode.com/problems/jump-game-ii/

#include<bits/stdc++.h>

using namespace std;
/*

naive approach 1:recursion
int helper(vector<int>& nums,int ind,int n,int stepcount){
    if(ind >= n-1){
        return stepcount;
    }
    int min_ele = 1e9;
    int res=0;
    for(int i=1;i<=min(n-1,nums[ind]);i++){
        res = min(min_ele,helper(nums,i+ind,n,stepcount+1));
    }
    return res;
}
int jump(vector<int>& nums) {
    return helper(nums,0,nums.size(),0);
}

int main(){
    vector<int> nums={2,4,0,1,8,3};
    cout << jump(nums);
}

*/

/*

approach 2:use dp

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1e9);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=nums[i];j++){
                dp[i]=min(dp[i],1+dp[ min(j+i,n-1) ]);
            }
        }
        
        return dp[0];
    }
};


*/


// testing random crap

int main(){
    cout << pow(2,3);
}