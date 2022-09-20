https://leetcode.com/problems/check-if-the-sentence-is-pangram/submissions/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool isPresent[26] = {0};
        
        for(char x:sentence){
            isPresent[x - 'a'] = 1;
        }
        
        for(int i=0;i<26;i++){
            if(isPresent[i] == 0){
                return 0;
            }
        }
        return 1;
    }
};