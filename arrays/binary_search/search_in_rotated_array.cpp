//https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int right = n-1;
        int left = 0;
        
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] >= nums[left]){     //left side is sorted
                if(target <= nums[mid] && target >= nums[left]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
               
                
            }
            
            else{
                if(target >= nums[mid] && target <= nums[right]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};