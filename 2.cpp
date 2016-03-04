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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int n1,n2,r,flag = 0;
        ListNode result(0);
        ListNode *p,*node;
        p = &result;
        while( (l1!=NULL) && (l2!=NULL) )
        {
            n1 = l1->val;
            n2 = l2->val;
            r = n1 + n2 + flag;
            
            node = new ListNode(0);
            node->val = r % 10;
            flag = (r/10 > 0) ? 1 : 0;
            
            p->next = node;
            p = node;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == NULL)
            l1 = l2;
        while(l1!=NULL)
        {
            node = new ListNode(0);
            node->val = l1->val + flag;
            
            flag = (node->val/10 == 0) ? 0 : 1;
            node->val = (node->val/10 == 0) ? node->val : 0;
            p->next = node;
            p = node;
            l1 = l1->next;
        }
        
        if(flag)
        {
            node = new ListNode(1);
            p->next = node;
        }
        p = result.next;
        return p;
    }
};
