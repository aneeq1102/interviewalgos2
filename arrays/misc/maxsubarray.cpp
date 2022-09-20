
// https://leetcode.com/problems/maximum-subarray/submissions/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0],currBest=0;
        
        for(int x:nums){
            currBest = max(currBest+x,x);
            
            res = max(res,currBest);
        }
        
        return res;
    }
};