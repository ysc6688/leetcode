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
    ListNode *merge2lists(ListNode *l1, ListNode *l2)
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode *head,*p;
        head = new ListNode(0);
        if(l1->val <= l2->val)
        {
            head->val = l1->val;
            l1 = l1->next;
        }
        else
        {
            head->val = l2->val;
            l2 = l2->next;
        }
        p = head;
        while(l1!=NULL && l2!=NULL)
        {
            ListNode *tmp = new ListNode(0);
            if(l1->val <= l2->val)
            {
                tmp->val = l1->val;
                p->next = tmp;
                p = p->next;
                l1 = l1->next;
            }
            else
            {
                tmp->val = l2->val;
                p->next = tmp;
                p = p->next;
                l2 = l2->next;
            }
        }
        if(l2 != NULL)
            l1 = l2;
        while(l1 != NULL)
        {
            ListNode *tmp = new ListNode(0);
            tmp->val = l1->val;
            p->next = tmp;
            p = p->next;
            l1 = l1->next;
        }
        return head;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<ListNode *> l;
        int count;
        if(lists.size() == 0)
            return NULL;
        while(lists.size() > 1)
        {
            l.clear();
            count = 0;
            for(int i=0;i<lists.size();i++)
            {
                if(i==lists.size()-1 && count==0)
                {
                    l.push_back(lists[i]);
                    break;
                }
                if(count==0)
                {
                    ++count;
                    continue;
                }
                else if(count == 1)
                {
                    l.push_back(merge2lists(lists[i-1],lists[i]));
                    count = 0;
                }
            }
            lists = l;
        }
        return lists[0];
    }
};
