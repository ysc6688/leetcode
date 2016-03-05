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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i = 0;
        vector<ListNode*> v;
        ListNode *ptr;
        ptr = head;
        
        while(ptr != NULL)
        {
            ++i;
            if(i >= m && i <= n)
                v.push_back(ptr);
            ptr = ptr->next;
        }
        
        ListNode *p = new ListNode(-1);
        p->next = head;
        i = 1;
        ptr = p;
        
        while(i < m)
        {
            ptr = ptr->next;
            ++i;
        }
        ListNode *begin = ptr;
        while(i <= n)
        {
            ptr = ptr->next;
            ++i;
        }
        ListNode *temp = ptr->next;
        ptr = begin;
        while(v.size() > 0)
        {
            ptr->next = v.back();
            v.pop_back();
            ptr = ptr->next;
        }
        ptr->next = temp;
        return p->next;
    }
};
