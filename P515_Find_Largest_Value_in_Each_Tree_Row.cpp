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
    vector<int> ans;
public:
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
    void dfs(TreeNode* root, int level){
        if(!root) return;
        if(ans.size() < level) ans.push_back(root->val);
        if(ans.size() >= level){
            ans[level-1] = (ans[level-1] > root->val) ? ans[level-1] : root->val;
        }
        
        dfs(root->right, level + 1);
        dfs(root->left, level + 1);
        return;
    }
};
