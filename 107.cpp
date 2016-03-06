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
    int getheight(TreeNode* root, int height)
    {
        if(root == NULL) return height;
        else
        {
            int l = getheight(root->left,height+1);
            int r = getheight(root->right,height+1);
            return l > r ? l : r;
        }
    }

    void dfs(TreeNode *root, int height, vector<vector<int>>& res, int h)
    {
        if(root == NULL) return ;
        else
        {
            res[h - 1 - height].push_back(root->val);
            dfs(root->left,height+1,res,h);
            dfs(root->right,height+1,res,h);
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        
        int height = getheight(root,0);
        res.resize(height);
        dfs(root,0,res,height);
        return res;
    }
};
