#include<iostream>
#include<vector>
using namespace std;

int findParent(int node,vector<int>& parent){
    if(node == parent[node]){
        return node;
    }

    return parent[node]=findParent(parent[node],parent);
}

void unionfind(int u,int v,vector<int>& rank,vector<int>& parent>){
    u = findParent(u,parent);
    v = findParent(v,parent);

    if(rank[u]<rank[v]){
        parent[u]=v;
    }else if(rank[v]>rank[u]){
        parent[u]=v;
    }else{
        parent[v]=u;
        rank[u]++;
    }
}

int main(){

    vector<int> rank(100);
    vector<int> parent(100);
    int n = 100;

    for(int i=0;i<n;i++){

        parent[i]=i;

        rank[i]=0;
    }




    return 0;
}