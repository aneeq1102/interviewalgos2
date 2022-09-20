class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            char curr = expression[i];
            
            if(curr == '+' || curr == '-' || curr == '*'){
                
                vector<int> left = diffWaysToCompute(expression.substr(0,i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                
                for(int x:left){
                    for(int y:right){
                        if(curr == '-'){
                            res.push_back(x - y);
                        }
                        else if(curr == '+'){
                            res.push_back(x + y);
                        }
                        else if(curr == '*'){
                            res.push_back(x * y);
                        }
                    }
                }
        
            
            }
            
        }
        
        if(res.empty()){
            res.push_back(stoi(expression));
        }
        return res;
    }
};