//  https://leetcode.com/problems/number-of-provinces/submissions/

class Solution {
public:
    void dfs(int node,vector<bool>& visited,vector<vector<int>>& isConnected){
        visited[node]=1;
        for(int j=0;j<visited.size();j++){
            if(isConnected[node][j] && !visited[j] && node!=j){
                dfs(j,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,0);
        int res=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                res++;
                dfs(i,visited,isConnected);
            }
        }
        return res;
    }
};