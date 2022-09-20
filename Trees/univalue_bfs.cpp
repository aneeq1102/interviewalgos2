// https://leetcode.com/problems/univalued-binary-tree/submissions/


#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    bool isUnivalTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            if(f-> val != root-> val){
                return 0;
            }
            if(f -> left){
                q.push(f -> left);
            }
            if(f -> right){
                q.push(f -> right);
            }
        }
        
        return 1;
    }
int main(){

    TreeNode* root = new TreeNode(1);

    root -> left = new TreeNode(1);
    root -> left -> left = new TreeNode(1);
    root -> left -> right = new TreeNode(1);
    root -> right = new TreeNode(1);
    root -> right -> right = new TreeNode(1);

    cout<<isUnivalTree(root);

    return 0;
}