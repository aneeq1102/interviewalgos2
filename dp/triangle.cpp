//  https://leetcode.com/problems/triangle/

#include<bits/stdc++.h>
using namespace std;

/*
int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp(triangle.size());
    for(int i=0;i<triangle.size();i++){
        dp[i]=vector<int>(i+1,0);
    }
    
    dp[0][0]=triangle[0][0];
    
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            dp[i][j] = min( dp[i-1][min(j-1,0)] , dp[i-1][min(j,(int)triangle[i-1].size()-1)] ) + triangle[i][j];
        }
    }
    int min_ele=1e9;
    for(int i=0;i<triangle[triangle.size()-1].size();i++){
        min_ele = min(min_ele,dp[triangle.size()-1][i]);
    }
    
    return min_ele;
}

*/
int minimumTotal(vector<vector<int>>& triangle) {
    
    
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            triangle[i][j] += min( triangle[i-1][min(j-1,0)] , triangle[i-1][min(j,(int)triangle[i-1].size()-1)] );
        }
    }
    int min_ele=1e9;
    for(int i=0;i<triangle[triangle.size()-1].size();i++){
        min_ele = min(min_ele,triangle[triangle.size()-1][i]);
    }
    
    return min_ele;
}
int main(){

    vector<vector<int>> v = {{2},{3,4},{6,5,7},{4,1,8,3}};

    cout << minimumTotal(v);

    
    return 0;
}