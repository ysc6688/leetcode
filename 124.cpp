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
    int Max;
public:
    int maxPath(TreeNode* root) {
        if( !root ) return -10000;
        
        int l = maxPath(root->left);
        int r = maxPath(root->right);
        
        int v = root->val;
        if(l > 0) v += l;
        if(r > 0) v += r;
        
        Max = max(Max,v);
        if(l <= 0 && r <= 0) return root->val;
        else return max(l,r) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        Max = INT_MIN;
        return max(Max,maxPath(root));
    }
};
