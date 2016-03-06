/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* build(ListNode* head, int length)
    {
        if(length  <= 0 || head == NULL) return NULL;
        int mid = length / 2;
        ListNode *temp = head;
        for(int i=0;i<mid;++i)
        {
            temp = temp->next;
        }
        TreeNode *root = new TreeNode(temp->val);
        root->left = build(head,mid);
        root->right = build(temp->next,length-mid-1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        int length = 0;
        ListNode *tmp = head;
        while(tmp != NULL)
        {
            ++length;
            tmp = tmp->next;
        }
        return build(head,length);
    }
};
