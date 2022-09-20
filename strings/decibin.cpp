https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/submissions/

class Solution {
public:
    int minPartitions(string n) {
        char maxch = '0';
        
        for(int i=0;i<n.size();i++){
            if(n[i]>maxch){
                maxch=n[i];
            }
        }
        
        return maxch-'0';
    }
};