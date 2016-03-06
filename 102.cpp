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
    vector<vector<int>> res;
public:
    void bfs(TreeNode* root, int level)
    {
        if(root != NULL)
        {
            level += 1;
            res[level].push_back(root->val);
            bfs(root->left,level);
            bfs(root->right,level);
        }
    }
    int height(TreeNode* root, int level)
    {
        if(root != NULL)
        {
            level += 1;
            int a = height(root->left,level);
            int b = height(root->right,level);
            return a>b ? a : b;
        }
        else
            return level;
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return res;
        int level = 0;
        int h = height(root,level);
        res.resize(h);
        for(int i=0;i<h;++i)
        {
            res[i].clear();
        }
        bfs(root,-1);
        return res;
    }
};
