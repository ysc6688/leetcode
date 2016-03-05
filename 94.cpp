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
    void intr(TreeNode* node, vector<int> &r)
    {
        if(node != NULL)
        {
            intr(node->left,r);
            r.push_back(node->val);
            intr(node->right,r);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        intr(root,result);
        return result;
    }
};
