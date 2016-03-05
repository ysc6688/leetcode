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
    ListNode* partition(ListNode* head, int x) {
        if( head == NULL || head->next == NULL) return head;
        ListNode *last,*newhead,*temp,*tmp,*ptr,*parent;
        
        newhead = new ListNode(-1);
        newhead->next = head;
        last = newhead;
        parent = newhead;
        ptr = head;
        
        bool partition = false;
        
        while(ptr != NULL)
        {
            if( !partition ) {
                if(ptr->val >= x)
                    partition = true;
                else
                    last = last->next;
                
                parent = ptr;
                ptr = ptr->next;
                continue;
            }
            else {
                if(ptr->val >= x)
                {
                    parent = ptr;
                    ptr = ptr->next;
                }
                else
                {
                    temp = last->next;
                    last->next = ptr;
                    tmp = ptr->next;
                    ptr->next = temp;
                    
                    parent->next = tmp;
                    
                    ptr = tmp;
                    last = last->next;
                }
            }
        }
        return newhead->next;
    }
};
