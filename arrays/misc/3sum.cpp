class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n<3){
            return {};
        }
           
       if(nums[0]>0){
           return {};
       }
        
        
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            int left = i+1;
            int right = n-1;
            
            if((i>0) && (nums[i-1] == nums[i])){
                continue;
            }
            while(left < right){
                
                
                int sum = nums[i] + nums[left] + nums[right];
                
                if(sum < 0){
                    left++;
                }
                
                else if(sum > 0){
                    right--;
                }
                else{
                    res.push_back({nums[right],nums[left],nums[i]});
                  int last_left = nums[left],last_right = nums[right];
                    
                    while(left < right && nums[left] == last_left){
                        left++;
                    }
                    
                    while( left<right && nums[right] == last_right ){
                        right--;
                    }
                    
                }
            
            }
        }
    
        return res;
    }
};

// https://seanprashad.com/leetcode-patt...


