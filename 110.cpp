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
    bool h(TreeNode* root, int& height)
    {
        if(root == NULL)
        {
            height = 0;
            return true;
        }
        int left,right;
        if( h(root->left,left) && h(root->right,right))
        {
            int c = left - right;
            if(c <= 1 && c >= -1)
            {
                height = (left > right) ? (left + 1) : (right + 1);
                return true;
            }
        }
        return false;
    }
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return h(root,height);
    }
};
