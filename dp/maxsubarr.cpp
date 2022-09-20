//https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int temp_sum=nums[0],sum=nums[0];
        for(int i=1;i<n;i++){
            
            if(nums[i]+temp_sum>nums[i]){
                temp_sum+=nums[i];
            }else{
                temp_sum=nums[i];
                
                
            }
            
            sum = max(temp_sum,sum);
            
        }
        return sum;
    }
};