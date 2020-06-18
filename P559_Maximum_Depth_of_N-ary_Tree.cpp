/*
// Definition for a Node.
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
*/

class Solution {
public:
    int result = 0;
    int maxDepth(Node* root) {
        if(!root) return 0;
        dfs(root, 1);
        return result;
    }
    void dfs(Node* root, int k){
        if(root->children.size()==0){
            if(k > result) result = k;
            return;
        }
        for(int i = 0; i < root->children.size(); i++){
            dfs(root->children[i], k+1);    
        }
        return;
    }
};
