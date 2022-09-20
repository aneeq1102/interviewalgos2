https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int count = 0;
        int left = 0;
        unordered_map<char,int> counts;
        for(int right=0;right<n;right++){
            
            counts[s[right]]++;
            
            if(right<2){
                continue;
            }
            
            while(right-left+1 > 3){
                counts[s[left]]--;
                left++;
            }
            
            if(counts[s[right]] == 1 && counts[s[left]] == 1 && counts[s[left+1]] ==1){
                count++;
            }
        }
        
        return count;
    }
};
int main(){

    cout << countGoodSubstrings("aababcabc");

    return 0;
}