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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if( !root ) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while( !q.empty() )
        {
            int size = q.size();
            TreeNode* ptr = NULL;
            for(int i = 0; i < size; ++ i)
            {
                ptr = q.front();
                q.pop();
                if(ptr->left) q.push(ptr->left);
                if(ptr->right) q.push(ptr->right);
            }
            res.push_back(ptr->val);
        }
        return res;
    }
};
