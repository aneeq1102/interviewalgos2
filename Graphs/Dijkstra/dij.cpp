#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int main(){
    int source = 1;
    vector<vector<pair<int,int>>> g = {
        {},
        {{2,2},{4,1}},
        {{5,5},{3,4}},
        {{5,1},{4,3},{2,4}},
        {{1,1},{3,3}},
        {{2,5},{3,1}}
    };

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> distTo(6,1e9);
    distTo[source] = 0;
    pq.push(make_pair(0,source));

    while(!pq.empty()){
        int minDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto x:g[node]){
            int dist_to = x.second;
            int toNode = x.first;
            if(minDist + dist_to < distTo[toNode]){
                distTo[toNode] = minDist + dist_to;
                pq.push(make_pair(distTo[toNode],toNode));
            }
        }
    }

    for(int x:distTo){
        cout<<x<<'\t';
    }

    return 0;

}