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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int i,lengthA,lengthB,diff;
        ListNode *cpA,*cpB;
        cpA = headA;
        cpB = headB;
        lengthA = lengthB = 0;
        while(cpA != NULL)
        {
            lengthA++;
            cpA = cpA->next;
        }
        while(cpB != NULL)
        {
            lengthB++;
            cpB = cpB->next;
        }
        diff = lengthA - lengthB;
        if(diff > 0)
        {
            for(i=0;i<diff;i++)
                headA = headA->next;
        }
        else {
            diff = -diff;
            for(i=0;i<diff;i++)
                headB = headB->next;
        }
        while(headA != NULL)
        {
            if(headA == headB)
                return headA;
            else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }
};
