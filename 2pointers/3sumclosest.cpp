//    https://leetcode.com/problems/3sum-closest/
    
   class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int min_sum = nums[0] + nums[1] + nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int left = i+1;
            int right=n-1;
            
            while(left<right){
                //min_sum = min(min_sum,nums[left]+nums[right]+nums[i]);
                int currSum = nums[left]+nums[right]+nums[i];
                if(abs(target-currSum) < abs(target - min_sum)){
                    min_sum = currSum;
                }
                if(currSum == target){
                    return min_sum;
                }
                else if(currSum>target){
                    right--;
                }
                else if(currSum<target){
                    left++;
                }
                
            }
        }
        
        return min_sum;
    }
};