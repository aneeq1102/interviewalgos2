#include<iostream>
#include<vector>
using namespace std;

void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
    subs.push_back(sub);
    for (int j = i; j < nums.size(); j++) {
        sub.push_back(nums[j]);
        subsets(nums, j + 1, sub, subs);
        sub.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subs;
    vector<int> sub;
    subsets(nums, 0, sub, subs);
    return subs;
}



int main(){

    vector<int> nums = {1,2,3};
    vector<vector<int>> res = subsets(nums);

    for(auto x:res){
        for(auto y:x){
            cout<<y<<' ';
        }
        cout<<'\n';
    }

    return 0;
}