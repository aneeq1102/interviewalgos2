//  https://leetcode.com/problems/unique-paths-ii/submissions/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size();
        int cols=obstacleGrid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,5));
        
        bool boulder_enc=0;
        for(int i=0;i<cols;i++){
           if(obstacleGrid[0][i] == 1 || boulder_enc){
               dp[0][i]=0;
               boulder_enc=1;
           }else{
               dp[0][i]=1;
           }
        }
        boulder_enc=0;
        for(int i=0;i<rows;i++){
            if(obstacleGrid[i][0] == 1 || boulder_enc){
                dp[i][0]=0;
                boulder_enc=1;
            }else{
                dp[i][0]=1;
            }
        }
        
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        
        return dp[rows-1][cols-1];
    }
};