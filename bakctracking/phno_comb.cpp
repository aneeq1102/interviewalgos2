class Solution {
public:
    vector<string> getChars(int x){
        if(x == 2){
            return {"a","b","c"};
        }
        if(x == 3){
            return {"d","e","f"};
        }
        if(x == 4){
            return {"g","h","i"};
        }
        if(x == 5){
            return {"j","k","l"};
        }
        if(x == 6){
            return {"m","n","o"};
        }
        if(x == 7){
            return {"p","q","r","s"};
        }
        if(x == 8){
            return {"t","u","v"};
        }
        if(x == 9){
            return {"w","x","y","z"};
        }
        
        return {""};
    }
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return {};
        }
        vector<string> res,temp;
        res.push_back("");
        for(char ch:digits){
            vector<string> chars = getChars(ch-'0');
            
            for(string c:chars){
                for(string s:res){
                    temp.push_back(s + c);
                }
            }
            res.swap(temp);
            temp.clear();
        }
        
        return res;
    }
};