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
    void dfs(TreeNode* root, string path, vector<string>& res)
    {
        char buf[20];
        sprintf(buf,"%d",root->val);
        string value(buf);
        path = path + "->" + value;
        
        if( !root->left && !root->right ){
            res.push_back(path);
            return ;
        }
        if( root->left ) dfs(root->left,path,res);
        if( root->right ) dfs(root->right,path,res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if( !root ) return res;
        
        char buf[20];
        sprintf(buf,"%d",root->val);
        string path(buf);
        
        if( !root->left && !root->right ){
            res.push_back(path);
            return res;
        }

        if(root->left) dfs(root->left,path,res);
        if(root->right) dfs(root->right,path,res);
        
        return res;
    }
};
