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
    ListNode* insertionSortList(ListNode* head) {
        if( !head || !head->next) return head;
        
        ListNode *ptr = head->next;
        ListNode *last = head;

        while( ptr )
        {
            ListNode *tmp = ptr->next;
            last->next = tmp;
            
            ListNode *hp = head;
            ListNode *before = NULL;
            while( hp != tmp && hp->val <= ptr->val)
            {
                before = hp;
                hp = hp->next;
            }
            
            if(hp == head)
            {
                ptr->next = head;
                head = ptr;
                ptr = tmp;
            }
            else if(hp == tmp)
            {
                last->next = ptr;
                ptr->next = tmp;
                last = ptr;
                ptr = tmp;
            }
            else
            {
                before->next = ptr;
                ptr->next = hp;
                ptr = tmp;
            }
        }
        return head;
    }
};
