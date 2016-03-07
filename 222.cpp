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
    int countNodes(TreeNode* root) {
        if( !root ) return 0;
        int height;
        if( avl(root,height) ) return pow(2,height + 1) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
    bool avl(TreeNode* root, int& h)
    {
        h = 0;
        if( !root ) return true;
        TreeNode *l,*r;
        l = root->left;
        r = root->right;

        while(l && r)
        {
            l = l->left;
            r = r->right;
            ++ h;
        }
        if( l && !r ) return false;
        else return true;
    }
};
