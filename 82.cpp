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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ptr,*last,*p,*newhead = NULL;
        bool isdup = false;

        if(head == NULL) return NULL;
        ptr = head->next;
        last = head;
        p = head;
        while(ptr != NULL)
        {
            if(ptr->val == last->val)
            {
                ptr = ptr->next;
                isdup = true;
            }
            else
            {
                if( isdup ) {
                    p->next = ptr;
                    last = ptr;
                    ptr = ptr->next;
                }
                else {
                    if(newhead == NULL)
                        newhead = last;
                    p = last;
                    last = ptr;
                    ptr = ptr->next;
                }
                isdup = false;
            }
        }
        if( isdup )
        {
            p->next = NULL;
        }
        else if( newhead == NULL )
            newhead = last;

        return newhead;
    }
};
