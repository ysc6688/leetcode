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
    bool isPalindrome(ListNode* head) {
        if( !head ) return true;
        int count = 0;
        ListNode* p = head;
        
        while( p )
        {
            ++ count;
            p = p->next;
        }
        
        if(count == 1) return true;
        
        p = head;
        for(int i = 0; i < count/2; ++ i)
            p = p->next;
            
        if(count & 1) p = p->next;
        
        ListNode *pre,*newhead;
        pre = NULL;
        while( p )
        {
            ListNode* next = p->next;
            if( !next ) 
            {
                p->next = pre;
                newhead = p;
                break;
            }
            
            p->next = pre;
            pre = p;
            p = next;
        }
        for(int i = 0; i < count / 2; ++ i)
        {
            if(head->val != newhead->val) return false;
            head = head->next;
            newhead = newhead->next;
        }
        return true;
    }
};
