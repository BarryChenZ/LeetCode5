/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string res;
    string tree2str(TreeNode* t) {
        dfs(t);
        return res;
    }
    void dfs(TreeNode* t){
        if(!t) return;
        res += to_string(t->val);
        if(t->left){
            res += "(";
            dfs(t->left);
            res += ")";
            if(t->right){
                res += "(";
                dfs(t->right);
                res += ")";
            }
        }
        else if(t->right){
            res += "()";
            res += "(";
            dfs(t->right);
            res += ")";
        }
        return;
    }
};
