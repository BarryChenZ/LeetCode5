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
    int res = INT_MAX;
    int val = -1;
    int getMinimumDifference(TreeNode* root) {
        return dfs(root); 
    }
    int dfs(TreeNode* root){
        if(root->left) dfs(root->left);
        if(val >= 0) res = min(res, root->val - val);
        val = root->val;
        if(root->right) dfs(root->right);
        return res;
    }
};
