class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int,bool> isPresent;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            isPresent[nums[i]] = 1;
        }
        
        for(int f:nums){
            if(isPresent[f+diff] && isPresent[f-diff]){
                count++;
            }
        }
        
        return count;
    }
};