/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode head(-1);
        int i,j;
        
        ListNode *p = &head;
        
        while( left && right )
        {
            if(left->val < right->val)
            {
                p->next = left;
                p = p->next;
                left = left->next;
            }
            else
            {
                p->next = right;
                p = p->next;
                right = right->next;
            }
        }
        
        while( left )
        {
            p->next = left;
            p = p->next;
            left = left->next;
        }
        
        while( right )
        {
            p->next = right;
            p = p->next;
            right = right->next;
        }
        return head.next;
    }
    ListNode* splt(ListNode* head, int l)
    {
        if(l == 1) return head;
        int i = 0;
        int mid = l >> 1;
        ListNode *p = head;
        while( i < mid - 1 )
        {
            p = p->next;
            ++ i;
        }
        
        ListNode *right = p->next;
        p->next = NULL;
        ListNode *left = head;
        left = splt(left,i + 1);
        right = splt(right,l - i - 1);
        return merge(left,right);
    }
    ListNode* sortList(ListNode* head) {
        if( !head || !head->next) return head;

        int length = 0;
        ListNode *p = head;
        while( p )
        {
            ++ length;
            p = p->next;
        }
        return splt(head,length);
    }
};
