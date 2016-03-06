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
    ListNode *detectCycle(ListNode *head) {
        if( !head ) return NULL;
        
        ListNode *first, *second;

        first = second = head;
        
        while(first && first->next)
        {
            first = first->next->next;
            second = second->next;
            
            if(first == second)
                break;
        }
        if( !first || !(first->next)) return NULL;
        
        second = head;
        while(first != second)
        {
            first = first->next;
            second = second->next;
        }
        return second;
    }
};
