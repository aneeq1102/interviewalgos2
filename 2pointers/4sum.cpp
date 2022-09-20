class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4){
            return {};
        }
        int minSum=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<4;i++) minSum += nums[i];
        
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int left = j+1;
                int right = n-1;
                
                while(left<right){
                    int currSum = nums[i]+nums[j]+nums[left]+nums[right];
                    
                    if(currSum < target){
                        left++;
                    }
                    else if(currSum > target){
                        right--;
                    }
                    else{
                        
                        res.push_back({nums[left],nums[right],nums[i],nums[j]});
                        int last_left = nums[left],last_right=nums[right];
                        
                        while(left<right && last_left == nums[left]) left++;
                        while(left<right && last_right == nums[right]) right--;
                    }
                }
            }
        }
        
        return res;
    }
};