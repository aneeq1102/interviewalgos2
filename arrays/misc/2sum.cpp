https://leetcode.com/problems/two-sum/submissions/

#include</home/aneeq/Public/bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> visited;
        int n = nums.size();
        for(int i=0;i<n;i++){
            
            if(visited.find(target-nums[i]) != visited.end()){
                return {i,visited[target-nums[i]]};
            }
            
            visited[nums[i]] = i;
        }
        
        return {};
    }
};

// we iterate throught the list once,for each eleemnt x we first check if target - x was already visisted,if so then we return the current element and the hashed index,other wise we return the current 
//element and the hashed index.