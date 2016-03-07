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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        
        TreeNode* p = root;
        
        while(p || !s.empty())
        {
            if( p )
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                TreeNode* top = s.top();
                s.pop();
                if(-- k == 0) return top->val;
                p = top->right;
            }
        }
    }
};
