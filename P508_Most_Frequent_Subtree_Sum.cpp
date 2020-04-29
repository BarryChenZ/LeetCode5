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
    unordered_map<int, int> m;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0);
        int tmp = 0;
        for(unordered_map<int,int>::iterator it = m.begin(); it != m.end(); it++){
            if(it->second > tmp){
                ans.clear();
                tmp = it->second;
                ans.push_back(it->first);
            }
            else if(it->second == tmp) ans.push_back(it->first);
        }
        return ans;
    }
    int dfs(TreeNode* root, int value){
        if(!root) return 0;
        int templ = dfs(root->left, value);
        int tempr = dfs(root->right, value);
        m[templ + tempr + root->val]++;
        return templ + tempr + root->val;
    }
};
