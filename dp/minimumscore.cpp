//  https://leetcode.com/problems/minimum-path-sum/submissions/

#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int rows=grid.size();
    int cols=grid[0].size();
    
    vector<vector<int>> dp(rows,vector<int>(cols));
    dp[0][0]=grid[0][0];
    
    for(int i=1;i<cols;i++){
        dp[0][i]=grid[0][i]+dp[0][i-1];
    }
    
    for(int i=1;i<rows;i++){
        dp[i][0]=grid[i][0]+dp[i-1][0];
    }
    
    for(int i=1;i<rows;i++){
        for(int j=1;j<cols;j++){
            int min_ele = min(dp[i-1][j],dp[i][j-1]);
            dp[i][j]=grid[i][j]+min_ele;
        }
    }
    
    return dp[rows-1][cols-1];
}

int main(){

    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    cout << minPathSum(grid);
    return 0;
}