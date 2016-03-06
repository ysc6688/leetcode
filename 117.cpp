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
        if( !root ) return ;
        
        root->next = NULL;
        TreeLinkNode *p, *head, *parent;
        
        p = head = root;
        
        if( root->left )
        {
            p = head = root->left;
        }
        else
        {
            p = head = root->right;
        }
        
        parent = root;
        
        while(p != NULL)
        {
                if( p == parent->left && parent->right )
                {
                    p->next = parent->right;
                    p = p->next;
                }
                else if( !parent->next )
                {
                    p->next = NULL;
                    TreeLinkNode *temp = head;
                    while( temp && (!temp->left && !temp->right) )
                    {
                        temp = temp->next;
                    }
                    if( !temp ) return;
                    else
                    {
                        p = temp->left==NULL ? temp->right : temp->left;
                        head = p;
                        parent = temp;
                    }
                }
                else
                {
                    TreeLinkNode *t = parent->next;
                    while( t && (!t->left && !t->right) )
                    {
                        t = t->next;
                    }
                    if( !t )
                    {
                        p->next = NULL;
                        TreeLinkNode *temp = head;
                        while( temp && (!temp->left && !temp->right) )
                        {
                            temp = temp->next;
                        }
                        if( !temp ) return;
                        else
                        {
                            p = temp->left==NULL ? temp->right : temp->left;
                            head = p;
                            parent = temp;
                        }
                    }
                    else
                    {
                        p->next = (t->left == NULL) ? t->right : t->left;
                        p = p->next;
                        parent = t;
                    }
                }
        }
    }
};
