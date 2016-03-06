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
    int dfs(TreeNode* root, int height)
    {
        if(root == NULL) return height;
        else
        {
            if(root->left == NULL && root->right == NULL) return height;
            else if(root->left == NULL)
            {
                return dfs(root->right,height+1);
            }
            else if(root->right == NULL)
            {
                return dfs(root->left,height+1);
            }
            else
            {
                int l = dfs(root->left,height+1);
                int r = dfs(root->right,height+1);
                return l < r ? l : r;
            }
        }
    }
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return dfs(root,1);
    }
};
