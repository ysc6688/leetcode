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
    bool path(TreeNode* root, TreeNode* p, vector<TreeNode*>& v)
    {
        if( !root ) return false;
        v.push_back(root);
        if(root == p) return true;
        
        if(path(root->left,p,v) || path(root->right,p,v)) return true;
        else
        {
            v.pop_back();
            return false;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( !root ) return NULL;
        if( root == p || root == q ) return root;
        
        vector<TreeNode*> p1,p2;
        
        path(root,p,p1);
        path(root,q,p2);
        
        int size = min(p1.size(),p2.size());
        TreeNode* common = root;
        for(int i = 1; i < size; ++ i)
        {
            if(p1[i]->val != p2[i]->val) break;
            else {
                common = p1[i];
            }
        }
        return common;
    }
};
