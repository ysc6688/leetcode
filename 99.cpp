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
    void midTraversal(TreeNode* root, TreeNode*& m1, TreeNode*& m2, TreeNode*& pre, TreeNode*& fl)
    {
        if(root != NULL)
        {
            midTraversal(root->left,m1,m2,pre,fl);
            if(pre == NULL)
                pre = root;
            else
            {
                if(m1 == NULL && root->val < pre->val)
                {
                    m1 = pre;
                    fl = root;
                }
                else if(m1 != NULL && root->val < fl->val)
                {
                    m2 = root;
                }
            }
            pre = root;
            midTraversal(root->right,m1,m2,pre,fl);
        }
    }
    
    void recoverTree(TreeNode* root) {
        if(root == NULL || (root->left==NULL && root->right==NULL))
            return ;
        TreeNode *m1, *m2, *pre, *fl;
        m1 = m2 = pre = fl = NULL;
        midTraversal(root,m1,m2,pre,fl);
        if(m1 != NULL && m2 == NULL)
            m2 = fl;
        if(m1 != NULL && m2 != NULL)
        {
            int tmp = m1->val;
            m1->val = m2->val;
            m2->val = tmp;
        }
    }
};
