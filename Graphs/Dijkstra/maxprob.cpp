
//  https://leetcode.com/problems/path-with-maximum-probability/submissions/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int,double>>> g(n);
        
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(make_pair(edges[i][1],succProb[i]));
            g[edges[i][1]].push_back(make_pair(edges[i][0],succProb[i]));
        }
        
        vector<double> toProb(n,0);
        
        priority_queue<pair<double,int>> pq;
        
        toProb[start] = 1;
        
        vector<bool> seen(n,0);
        pq.push(make_pair((double)1.0,start));
        
        while(!pq.empty()){
            int node = pq.top().second;
            double prob = pq.top().first;
            
            pq.pop();
            
            if(!seen[node]){
                seen[node]=1;
                for(auto& it:g[node]){
                    int toNode = it.first;
                    double travProb = it.second;
                    
                    if(toProb[toNode] < prob*travProb){
                        toProb[toNode] = prob*travProb;
                        pq.push(make_pair(toProb[toNode],toNode));
                    }
                }
            }
        }
        
        return toProb[end];
    }
};