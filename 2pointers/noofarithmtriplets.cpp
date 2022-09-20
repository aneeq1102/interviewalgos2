//  https://leetcode.com/problems/number-of-arithmetic-triplets/


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

// maintiain a seen set,increment count if for number x in input array x - diff and x - 2*diff is present in seen;