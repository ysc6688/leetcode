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
        ListNode *ptr,*last;
        ptr = head;
        
        if(ptr == NULL) return NULL;
        
        last = ptr;
        ptr = ptr->next;
        while(ptr != NULL)
        {
            if(ptr->val == last->val)
                last->next = ptr->next;
            else
                last = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};
