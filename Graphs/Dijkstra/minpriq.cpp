#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class comparator{
    public:
    bool operator()(const pair<int,int>& l,const pair<int,int>& r){
        return l.first > r.first;
    }
};

int main(){

    priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> pq;

    pq.push(make_pair(2,12));
    pq.push(make_pair(16,12));
    pq.push(make_pair(9,12));

    while(!pq.empty()){
        cout<<pq.top().first<<'\n';
        pq.pop();
    }

    return 0;
}