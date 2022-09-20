// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

#include<iostream>
#include<vector>
using namespace std;

vector<int> res;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void helper(Node* root){
    if(!root){
        return;
    }
    
    for(Node* child:root -> children){
        helper(child);
        
        
    }
    
    res.push_back(root -> val);
}
vector<int> postorder(Node* root) {
    helper(root);
    
    return res;
}

int main(){

    
    Node* five = new Node(5);
    Node* six = new Node(6);
    Node* three = new Node(3,{five,six});
    Node* two = new Node(2);
    Node* four = new Node(4);
    Node* root = new Node(1,{three,two,four});
    
    vector<int> v = postorder(root);

    for(int x:v){
        cout<<x<<'\t';
    }

    return 0;
}