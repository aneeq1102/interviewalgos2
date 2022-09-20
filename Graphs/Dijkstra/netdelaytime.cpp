https://leetcode.com/problems/network-delay-time/submissions/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distTo(n+1,1e9);
        distTo[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(make_pair(0,k));
        
        while(!pq.empty()){
            int startNode = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(vector<int>& x:times){
                if(x[0]==startNode){
                    int toNode = x[1];
                    int tempDist = dist + x[2];
                    
                    if(tempDist < distTo[toNode]){
                        distTo[toNode] = tempDist;
                        pq.push(make_pair(tempDist,toNode));
                    }
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;i++){
            if(distTo[i]==1e9) return -1;
            res = max(res,distTo[i]);
        }
        
        return res;
    }
};