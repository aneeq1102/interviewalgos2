// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/submissions/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0,res=0;
        int z_count = 0;
        for(int right=0;right<nums.size();right++){
            
            if(nums[right] == 0 ){
                z_count++;    
            }
                
            
            while(z_count > 1){
                if(nums[left] == 0){
                    z_count--;
                }
                left++;
            }
            
                
           
            
            
            res = max(res,right - left);
            
        }
        return res;
    }
};