//  https://leetcode.com/problems/permutations/

#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>& nums,vector<int>& permutation,vector<bool>& visited,vector<vector<int>>& res){
    if(nums.size()==permutation.size()){
        res.push_back(permutation);
        return;
    }
    
    for(int i=0;i<nums.size();i++){
        if(!visited[i]){
            visited[i]=1;
            permutation.push_back(nums[i]);
            helper(nums,permutation,visited,res);
            visited[i]=0;
            permutation.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> perm;
    vector<bool> visited(nums.size(),0);
    helper(nums,perm,visited,res);
    return res;
}


int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = permute(nums);

    for(auto x:res){
        for(auto y:x){
            cout << y;
        }
        cout << endl;
    }
    return 0;
}