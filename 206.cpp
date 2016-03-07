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
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead = NULL;
        ListNode* pNode = head;
        ListNode* pPre = NULL;
        
        while( pNode )
        {
            ListNode* pNext = pNode->next;
            if( !pNext ) newhead = pNode;
            
            pNode->next = pPre;
            pPre = pNode;
            pNode = pNext;
        }
        
        return newhead;
    }
};
