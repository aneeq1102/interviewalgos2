https://leetcode.com/problems/decode-the-message/submissions/

class Solution {
public:
    string decodeMessage(string key, string message) {
        int num=0;
        unordered_map<char,int> k;
        for(char ch:key){
            if(k.find(ch) == k.end() && ch != ' '){
                k[ch] = num;
                num++;
            }
        }
        
        string res;
        
        for(char ch:message){
            if(ch == ' '){
                res += ' ';
                continue;
            }
            res += char('a' + k[ch]);
        }
        return res;
    
    }
};