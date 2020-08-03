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
    bool res = false;
    bool isSubtree(TreeNode* s, TreeNode* t) {
        find(s, t);
        return res;
    }
    void find(TreeNode* s, TreeNode* t){
        if(!s) return;
        if(s->val == t->val){
            bool i = true;
            SubtreeIS(s, t, i);
            if(i == true) res = true;
        }
        if(res == true) return;
        find(s->left, t);
        find(s->right, t);
    }
    void SubtreeIS(TreeNode* s, TreeNode* t, bool &i){
        if(!s && !t) return;
        if((!s && t) || (s && !t)){
            i = false;
            return;
        }
        if(s->val != t-> val){
            i = false;
            return;
        }
        SubtreeIS(s->left, t->left, i);
        SubtreeIS(s->right, t->right, i);
    }
};
