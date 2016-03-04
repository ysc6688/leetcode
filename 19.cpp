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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *tmp = head;
        int count = 0;
        while(tmp != NULL)
        {
            ++count;
            tmp = tmp->next;
        }
        if(count == 1)
        {
            delete head;
            return NULL;
        }
        int index = count - n;
        if(index == 0)
        {
            tmp = head->next;
            delete head;
            return tmp;
        }
        tmp = head;
        for(int i=0;i<index-1;++i)
            tmp = tmp->next;
        ListNode *node = tmp->next;
        tmp->next = node->next;
        delete node;
        return head;
    }
};
