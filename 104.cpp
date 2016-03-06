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
        int left = dfs(root->left,height+1);
        int right = dfs(root->right,height+1);
        return left > right ? left : right;
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        else return dfs(root,0);
    }
};
