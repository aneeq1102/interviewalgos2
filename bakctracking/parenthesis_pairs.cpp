https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    
    void helper(vector<string>& res,string temp,int open_ct,int close_ct,int max_ct){
    if(open_ct == max_ct && close_ct == max_ct){
        res.push_back(temp);
        return;
    }

    if(open_ct < max_ct){
        helper(res,temp+"(",open_ct + 1 , close_ct,max_ct);
    }

    if(close_ct < open_ct){
        helper(res,temp+")",open_ct,close_ct + 1,max_ct);
    }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        
        helper(res,"",0,0,n);
        
        return res;
    }
    

};