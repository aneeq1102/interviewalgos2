#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int node,vector<int>& visited,vector<vector<int>>& adj,vector<int>& res){
    res.push_back(node);
    
    visited[node]=1;
    for(int x:adj[node]){
        if(!visited[x]){
            dfs(x,visited,adj,res);
        }
    }
}

int main(){
    
    vector<int> res;
    vector<vector<int>> adj{
        {},
        {2},
        {4,7},
        {5},
        {2,6},
        {3},
        {4,7},
        {2,6}
    };

    int n=adj.size();
    vector<int> visited(n+1,0);
    
    for(int i=1;i<n;i++){
        if(!visited[i]){
            dfs(i,visited,adj,res);
        }
    }


   
    for(int x:res){
        cout<<x<<" ";
    }
   
    return 0;
}




































