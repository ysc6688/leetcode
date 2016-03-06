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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;

        stack<TreeNode*> s;
        TreeNode* p = root;
        
        while(p || !s.empty())
        {
            s.push(p->right);
            s.push(p->left);
            v.push_back(p->val);

            p = s.top();
            s.pop();
            while( !p && !s.empty() )
            {
                p = s.top();
                s.pop();
            }
        }
        
        return v;
    }
};
