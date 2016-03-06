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
    map<int,int> m;
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                int il, int ir, int pl, int pr)
    {
        if(pr < pl || ir < il)
            return NULL;
        TreeNode *root = new TreeNode(postorder[pr]);
        int pos = m[postorder[pr]];

        root->left = build(inorder,postorder,il,pos-1,pl,pl+pos-il-1);
        root->right = build(inorder,postorder,pos+1,ir,pos-il+pl,pr-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        for(int i=0;i<inorder.size();++i)
            m.insert(make_pair(inorder[i],i));
        return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};
