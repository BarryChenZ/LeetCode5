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
private:
    int ans = 0;
    int level = 0;
public:
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0 + 1);
        return ans;
    }
    void dfs(TreeNode* root, int k){
        if(!root) return; 
        dfs(root->left, k+1);
        dfs(root->right, k+1);
        if(k > level){
            ans = root->val;
            level = k;
        }
        return;
    }
};
