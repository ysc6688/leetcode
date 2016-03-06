/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *createTree(vector<int> &preorder, int preBeg, int preEnd, vector<int> &inorder, int inBeg, int inEnd)
    {
        if (preBeg > preEnd)
            return NULL;
            
        int root = preorder[preBeg];
        int index;
        for(int i = inBeg; i <= inEnd; i++)
            if (root == inorder[i])
            {
                index = i;
                break;
            }
        
        int len = index - inBeg;
        TreeNode *left = createTree(preorder, preBeg + 1, preBeg + len, inorder, inBeg, index - 1);
        TreeNode *right = createTree(preorder, preBeg + len + 1, preEnd, inorder, index + 1, inEnd);
        
        TreeNode *node = new TreeNode(root);
        
        node->left = left;
        node->right = right;
        
        return node;        
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (preorder.size() == 0)
            return NULL;
            
        TreeNode *head = createTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        
        return head;
    }
};
