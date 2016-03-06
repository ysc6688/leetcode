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
    long sum;
public:
    void dfs(TreeNode* root,long num)
    {
            num = num * 10 + root->val;
            if(root->left == NULL && root->right == NULL)
            {
                sum += num;
                return ;
            }
            if(root->left) dfs(root->left,num);
            if(root->right) dfs(root->right,num);
    }
    int sumNumbers(TreeNode* root) {
        if( !root ) return 0;
        sum = 0;
        dfs(root,0);
        if(sum > 0x7fffffff) return 0;
        else return sum;
    }
};
