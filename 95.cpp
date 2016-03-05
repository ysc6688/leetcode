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
    void dfs(int st,int ed,vector<TreeNode*> &res){
        if(st > ed)
        {
            res.push_back(NULL);
            return ;
        }
        for(int i=st;i<=ed;++i)
        {
            vector<TreeNode*> left;
            dfs(st,i-1,left);
            vector<TreeNode*> right;
            dfs(i+1,ed,right);
            
            for(int j=0;j<left.size();++j)
                for(int k=0;k<right.size();++k)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    res.push_back(root);
                }
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        dfs(1,n,result);
        return result;
    }
};
