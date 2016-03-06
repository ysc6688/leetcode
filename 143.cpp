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
    void reorderList(ListNode* head) {
        if( !head ) return ;
        
        ListNode *p;
        int count = 0;
        p = head;
        while( p )
        {
            p = p->next;
            ++ count;
        }
        
        int num = 0;
        int half = count >> 1;
        if( !(count&1) ) half -= 1;
        p = head;
        while( num < half )
        {
            p = p->next;
            ++ num;
        }
        
        ListNode *last;
        last = p->next;
        p->next = NULL;
        p = last;
        last = NULL;
        
        while( p )
        {
            ListNode *temp = p->next;
            p->next = last;
            last = p;
            p = temp;
        }
        
        p = head;
        num = 0;
        while( num < count)
        {
            if( num & 1 )
            {
                ListNode *temp = last->next;
                last->next = p;
                last = temp;
            }
            else
            {
                ListNode *temp = p->next;
                p->next = last;
                p = temp;
            }
            ++ num;
        }
    }
};
