// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/discuss/516977/JavaC%2B%2BPython-Easy-and-Concise     more similar problems

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left = 0;
        int count[] = {0,0,0};
        int res = 0;
        for(int right=0;right<n;right++){
            count[s[right] - 'a']++;
            
            while(count[0] && count[1] && count[2]){
                count[s[left] - 'a']--;
                left++;
            }
            
            res += left;
            
        }
        
        return res;
        
    }
};

// we maintain a left and right pointer and keep track of the counts of each character,right pointer is initialised to zero, we run a loop iterating over right pointer,we increment the value of each character at right pointer,if counts of all chars >=1 , then we continuously increment left and decrement the count of char at left until count of either a,b or c hits 0.
// consider the example abcabc,if left is at 1 and right is at 3, then left is incremented by 1,and then