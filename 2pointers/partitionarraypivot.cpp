// https://leetcode.com/problems/partition-array-according-to-given-pivot/

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        set<int> seen;
        int count = 0;
        for(int x:nums){
            if(seen.find(x - diff) != seen.end() && seen.find(x - 2*diff) != seen.end()){
                count++;
            }
            
                seen.insert(x);
            
        }
        return count;
    }
};