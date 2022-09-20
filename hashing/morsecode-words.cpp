#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string translations[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> morse;
        string temp;
        for(string s:words){
            for(char ch:s){
                
                temp += translations[ch - 'a'];
            }
            morse.insert(temp);
            temp.clear();
        }
        
        
            
        
        return morse.size();
    }
};


int main(){



    vector<string> words = {"rwjje","aittjje","auyyn","lqtktn","lmjwn"};



    cout << uniqueMorseRepresentations(words);





    return 0;
}