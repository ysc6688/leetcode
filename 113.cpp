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
    void dfs(TreeNode* root, vector<vector<int>>& res, vector<int>& rec, int sum)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            if(root->val == sum)
            {
                rec.push_back(sum);
                res.push_back(rec);
                rec.pop_back();
            }
            return ;
        }
        else
        {
            rec.push_back(root->val);
            dfs(root->left,res,rec,sum - root->val);
            dfs(root->right,res,rec,sum - root->val);
            rec.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int>rec;
        if(root == NULL)
            return res;
        dfs(root,res,rec,sum);
        return res;
    }
};
