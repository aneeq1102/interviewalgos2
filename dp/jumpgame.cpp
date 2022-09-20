// https://leetcode.com/problems/jump-game/submissions/


// naive solution

#include<bits/stdc++.h>
using namespace std;

class naive {
public:
    bool canJump(vector<int>& nums) {
        if(nums[0]==0 && nums.size()>1){
            return 0;
        }
        else if(nums[0]==0 && nums.size()==1){
            return 1;
        }
        int n=nums.size();
        vector<bool> canVisit(n,0);
        
        canVisit[0]=1;
        
        for(int i=0;i<n;i++){
            if(canVisit[i]){
                for(int j=1;j<=nums[i];j++){
                    if(j+i<n){
                        canVisit[j+i]=1;
                    }
                }
            }
        }
        
        if(canVisit[n-1]){
            return 1;
        }else{
            return 0;
        }
        
        
    }
};

// best solution O(n)

class best {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int lastgoodind = n-1;
       
        vector<bool> canReach(n,0);
        for(int i=n-1;i>=0;i--){
            if(i + nums[i]>=lastgoodind){
                lastgoodind=i;
            }
        }
        
        if(lastgoodind==0){
            return 1;
        }else{
            return 0;
        }
    }
};

// top down dp (TLE)

class topdown {
public:
    bool helper(vector<int>& nums,int n,int ind){
        if(ind>=n-1){
            return 1;
        }
        int it = min(n-1,nums[ind]+ind);
        for(int i=ind+1;i<=it;i++){
            if(helper(nums,n,i)){
                return 1;
            }
        }
        return 0;
    }
    bool canJump(vector<int>& nums) {
        return helper(nums,nums.size(),0);
    }
};

// bottom up dp
class bottomup {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n,0);
        
        dp[n-1]=1;
        
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<= min(n-1,i+nums[i] ) ;j++){
                if(dp[j]){
                    dp[i]=1;
                    break;
                }
            }
        }
        
        return dp[0];
    }
};

int main(){

    vector<int> nums = {2,4,0,1,8};
    cout << canJump(nums);


    return 0;
}