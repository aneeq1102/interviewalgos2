class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(original == NULL){
            return NULL;
        }
        
        if(original == target){
            return cloned;
        }
        
        TreeNode* lft = getTargetCopy(original -> left,cloned -> left,target);
        TreeNode* rght = getTargetCopy(original -> right,cloned -> right,target);
        
        if(lft == NULL){
            return rght;
        }
        return lft;
    }
};