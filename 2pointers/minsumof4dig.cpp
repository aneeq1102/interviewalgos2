https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

class Solution {
public:
    int minimumSum(int num) {
        string str = to_string(num);
        
        sort(str.begin(),str.end());
        
        return (str[0]-'0')*10 + (str[2]-'0') + (str[1]-'0')*10 + (str[3]-'0');
    }
};