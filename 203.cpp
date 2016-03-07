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
    ListNode* removeElements(ListNode* head, int val) {
        if( !head ) return head;
        
        while(head && head->val == val)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        
        ListNode* ptr = head;
        
        while( ptr )
        {
            if( ptr->next == NULL ) return head;
            else if(ptr->next->val == val)
            {
                ListNode* temp = ptr->next;
                ptr->next = temp->next;
                delete temp;
            }
            else ptr = ptr->next;
        }
        return head;
    }
};
