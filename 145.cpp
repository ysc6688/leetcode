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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if( !root ) return res;
        stack<TreeNode*> s;
        TreeNode *last = NULL,*p;
        
        p = root;
        s.push(p);
        
        while( p || !s.empty() )
        {
            if( !p )
            {
                s.pop();
                p = s.top();
                continue;
            }
            
            if( last == p )
            {
                s.pop();
                res.push_back(p->val);
                if( !s.empty() )
                {
                    p = s.top();
                    continue;
                }
                else
                    break;
            }
            
            if( last && (last == p->left || last == p->right) )
            {
                s.pop();
                res.push_back(p->val);
                last = p;
                if( !s.empty() )
                {
                    p = s.top();
                    continue;
                }
                else
                    break;
            }
            else
            {
                s.push(p->right);
                s.push(p->left);
            }
            
            last = p;
            p = s.top();
        }
        return res;
    }
};
