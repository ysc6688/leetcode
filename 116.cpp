/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return ;
        
        TreeLinkNode *p,*head,*parent;
        
        p = root;
        head = root;
        p->next = NULL;
        parent = p;
        p = p->left;
        while(p != NULL)
        {
            if(p == parent->left)
            {
                p->next = parent->right;
                p = p->next;
            }
            else
            {
                parent = parent->next;
                if(parent == NULL)
                {
                    p->next = NULL;
                    parent = head;
                    p = head->left;
                    head = p;
                }
                else
                {
                    p->next = parent->left;
                    p = p->next;
                }
            }
        }
    }
};
