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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenhead = even;
        ListNode *p = even->next;
        
        while( p )
        {
            odd->next = p;
            odd = p;
            p = p->next;
            
            even->next = p;
            even = p;
            if( p )
                p = p->next;
            else
                break;
        }
        
        odd->next = evenhead;
        
        return head;
    }
};
