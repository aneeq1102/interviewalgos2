// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int right=0,left=0,maxCount=0,z_count=0;
        
        for(int right=0;right<nums.size();right++){
            
            if(nums[right] == 0){
                z_count++;
            }
            
            while(z_count > k){
                if(nums[left] == 0){
                    z_count--;
                }
                left++;
            }
            
            maxCount = max(maxCount,right-left+1);
        }
        
        return maxCount;
    }
};

/*
    we maintain a left and right pointer,we have a for loop that incremenets the right pjointed,if there is a 0 at right pjointer,we increment zerou count,if zero count goes beyond k,we continue to increment left until left reaches a zero and increment left by one more step
*/