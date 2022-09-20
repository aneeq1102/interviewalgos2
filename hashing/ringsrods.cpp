https://leetcode.com/problems/rings-and-rods/

class Solution {
public:
    int countPoints(string rings) {
        vector<vector<int>> present(101,vector<int>(3)); // r - 0 g - 1 b - 2
        int max_num = 1;
        for(int i=0;i<rings.size();i+=2){
            int currNo = rings[i+1] - '0';
            int color;
            if(rings[i] == 'R') color=0;
            else if(rings[i] == 'G') color =1;
            else color = 2;
            
            present[currNo][color] = 1;
            max_num = max(max_num,currNo);
        }
        int count = 0;
        for(int i=0;i<=max_num;i++){
            if(present[i][0] && present[i][1] && present[i][2]){
                count++;
            }
        }
        
        return count;
    }
};