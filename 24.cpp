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
    ListNode *swapPairs(ListNode *head) {
        if( !head )
            return NULL;
        if( head->next == NULL)
            return head;
        
        ListNode *p,*tmp,*pre,*post;
        p = head;
        int flag = 1;
        p = head->next;
        tmp = p->next;
        p->next = head;
        head->next = tmp;
        pre = head;
        head = p;
        p = tmp;
        while(p!=NULL && p->next!=NULL)
        {
            tmp = p->next;
            pre->next = tmp;
            post = tmp->next;
            tmp->next = p;
            p->next = post;
            pre = p;
            p = p->next;
        }
        return head;
    }
};
