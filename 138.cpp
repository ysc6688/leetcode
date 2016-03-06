/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
 struct hash_func{
   size_t operator() (const RandomListNode * ln) const {
       return ln->label * 31;
   }
 };
 
 typedef unordered_map<RandomListNode*,RandomListNode*,hash_func> HASH;
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if( !head ) return NULL;
        
        RandomListNode *cphead = new RandomListNode(head->label);
        RandomListNode *ptr = head->next, *cptr = cphead;
        
        HASH hash;
        hash.insert(make_pair(head,cphead));
        for(; ptr != NULL; )
        {
            RandomListNode *node = new RandomListNode(ptr->label);
            hash.insert(make_pair(ptr,node));
            cptr->next = node;
            cptr = node;
            ptr = ptr->next;
        }
        
        ptr = head;
        cptr = cphead;
        
        for(; ptr != NULL; )
        {
            if(ptr->random) {
                HASH::iterator it = hash.find(ptr->random);
                cptr->random = it->second;
            }
            else
                cptr->random = NULL;
            ptr = ptr->next;
            cptr = cptr->next;
        }
        return cphead;
    }
};
