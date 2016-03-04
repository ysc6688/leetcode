struct listNode{
    int index;
    listNode* next;
    listNode(int x) : index(x), next(NULL) {}
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int size = nums.size();
        
        if( !size ) return res;
        
        unordered_map<int,listNode*> m;
        for(int i = 0; i < size; ++ i)
        {
            unordered_map<int,listNode*>::iterator it = m.find(nums[i]);
            if(it == m.end())
            {
                listNode *node = new listNode(i);
                m.insert(make_pair(nums[i],node));
            }
            else
            {
                listNode* p = it->second;
                while( p->next )
                    p = p->next;
                p->next = new listNode(i);
            }
        }
        
        for(int i = 0; i < size; ++ i)
        {
            int val = target - nums[i];
            unordered_map<int,listNode*>::iterator it = m.find(val);
            
            if(it != m.end())
            {
                listNode* p = it->second;
                if(p->index == i) p = p->next;
                
                if(p != NULL)
                {
                    res.push_back(i);
                    res.push_back(p->index);
                    return res;
                }
            }
        }
        
    }
};