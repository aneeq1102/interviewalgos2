https://leetcode.com/problems/3sum/
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            int left = 0;
            
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            for(int right = n-1;right>left;right--){
                int sum = nums[right] + nums[left] + nums[i];
                
                if(sum > 0){
                    right--;
                }
                else if(sum < 0){
                    left++;
                }
                else{
                    res.push_back({nums[left], nums[right], nums[i]});
                    
                    while(nums[left] == nums[left+1] && left+1<right){
                        left++;
                    }
                    
                    while(nums[right] == nums[right-1] && right-1>left){
                        right--;
                    }
                    
                }
            }
        }
    }


    // solution

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