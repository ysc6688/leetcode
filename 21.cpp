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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head,*p;
        if(l1==NULL && l2==NULL)
            return NULL;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        p = new ListNode(0);
        head = p;
        if(l1->val <= l2->val)
        {
            p->val = l1->val;
            l1 = l1->next;
        }
        else
        {
            p->val = l2->val;
            l2 = l2->next;
        }
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val <= l2->val)
            {
                ListNode *tmp = new ListNode(l1->val);
                p->next = tmp;
                p = p->next;
                l1 = l1->next;
            }
            else
            {
                ListNode *tmp = new ListNode(l2->val);
                p->next = tmp;
                p = p->next;
                l2 = l2->next;
            }
        }
        while(l1!=NULL)
        {
            ListNode *tmp = new ListNode(l1->val);
            p->next = tmp;
            p = p->next;
            l1 = l1->next;
        }
        while(l2!=NULL)
        {
            ListNode *tmp = new ListNode(l2->val);
            p->next = tmp;
            p = p->next;
            l2 = l2->next;
        }
        return head;
    }
};
