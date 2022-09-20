// https://leetcode.com/problems/longest-repeating-character-replacement/submissions/



class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,res=0;
        int counts[26] = {0};
        int max_char_count=0;
        char max_char;
        for(int right=0;right<s.size();right++){
            counts[s[right] - 'A']++;
            
            max_char_count = max(counts[s[right] - 'A'],max_char_count);
            
            while((right-left) - max_char_count +1> k){
                counts[s[left] - 'A']--;
                left++;
            }
            
            res = max(res,right-left+1);
        }
        
        return res;
    }
};