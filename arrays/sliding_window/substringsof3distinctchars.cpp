// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/

class Solution {
public:
    int countGoodSubstrings(string s) {
        int dup=0;
        int map[26] = {0};
        int count = 0;
        for(int i=0;i<s.size();i++){
            
            map[s[i]-'a']++;
            
            if(map[s[i]-'a'] == 2){
                dup++;
            }
            
            if(i <= 1){
                continue;
            }
            
            if(dup == 0){
                count++;
            }
            
            map[s[i-2]-'a']--;
            
            if(map[s[i-2] - 'a'] == 1){
                dup--;
            }
        }
        
        return count;
    }
};