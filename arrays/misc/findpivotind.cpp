//  https://leetcode.com/problems/find-pivot-index/

#include</home/aneeq/Public/bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0;
        for(int x:nums){
            total += x;
        }
        int sum = 0;
        for(int i=0;i<nums.size();sum += nums[i++]){
            
            if(2 * sum == total - nums[i]){
                return i;
            }
        }
        return -1;
    }
};


// if 2*cummulative_sum == total - nums[i],then i is index
// or total - pivot = sum of elements to left of pivot + sum of elemtents to right of pivot