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
    int find_min(TreeNode* root)
    {
        while(root->left != NULL)
        {
            root = root->left;
        }
        return root->val;
    }
    int find_max(TreeNode* root)
    {
        while(root->right != NULL)
            root = root->right;
        return root->val;
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        if(root->left == NULL && root->right == NULL)
            return true;
        else if(root->left == NULL && root->right != NULL)
        {
            if(root->right->val <= root->val || find_min(root->right) <= root->val)
                return false;
            else
                return isValidBST(root->right);
        }
        else if(root->left != NULL && root->right == NULL)
        {
            if(root->left->val >= root->val || find_max(root->left) >= root->val)
                return false;
            else
                return isValidBST(root->left);
        }
        else
        {
            if(root->right->val <= root->val || root->left->val >= root->val || find_min(root->right) <= root->val || find_max(root->left) >= root->val)
                return false;
            else
                return isValidBST(root->left)&&isValidBST(root->right);
        }
        
    }
};
