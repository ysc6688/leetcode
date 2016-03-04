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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if( !head )
            return NULL;
        if( head->next==NULL || k==1)
            return head;
        int count = 0;
        ListNode *pre,*tmp,*post;
        tmp = head;
        while( tmp )
        {
            if(++count == k)
                break;
            tmp = tmp->next;
        }
        if(count < k)
            return head;
        vector<ListNode *> v;
        tmp = head;
        for(int i=0;i<k;i++)
        {
            v.push_back(tmp);
            tmp = tmp->next;
        }
        post = tmp;
        head = v.back();
        pre = head;
        for(int i=k-2;i>=0;--i)
        {
           tmp = v[i];
           pre->next = tmp;
           pre = pre->next;
        }
        pre->next = reverseKGroup(post,k);
        return head;
    }
};
