/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<int,int> dfs(TreeNode* root)
    {
        if( !root ) return make_pair(0,0);
        pair<int,int> l,r;
        l = dfs(root->left);
        r = dfs(root->right);
        
        pair<int,int> res;
        res.first = l.second + r.second + root->val;
        res.second = std::max(l.first,l.second) + std::max(r.first,r.second);
        return res;
    }
    int rob(TreeNode* root) {
        pair<int,int> res = dfs(root);
        return std::max(res.first,res.second);
    }
};
