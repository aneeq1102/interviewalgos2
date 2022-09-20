#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> bfs(int n,vector<vector<int>> adj){
    vector<bool> visited(n+1,0);
    vector<int> bfs;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            queue<int> q;
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
                int ele = q.front();
                bfs.push_back(ele);
                q.pop();
                for(int x:adj[ele]){
                    if(!visited[x]){
                        q.push(x);
                        visited[x]=1;
                    }
                }

            }
        }
    }

    return bfs;
}

int main(){
    vector<vector<int>> v = {
        {},
        {2},
        {3,7},
        {5,2},
        {6},
        {3,7},
        {4},
        {2,3}
    };

    vector<int> res = bfs(7,v);

    for(int x:res){
        cout<<x<<'\t';
    }

}