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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        ListNode *temp = head, *last;
        int count = 0;
        
        while(temp != NULL)
        {
            count++;
            last = temp;
            temp = temp->next;
        }
        
        k = k % count;
        if(k == 0)
            return head;
        
        last->next = head;
        int begin = count - k;
        
        temp = head;
        for(int i=0;i<begin-1;++i)
            temp = temp->next;
        
        last = temp->next;
        temp->next = NULL;
        
        return last;
    }
};
