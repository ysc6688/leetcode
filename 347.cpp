class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        int len = nums.size();
        if(!len || k <= 0) return res;
        
        unordered_map<int,int> um;

        for(int i = 0; i < len; ++ i)
            um[nums[i]] ++;

        multimap<int,int> m;
        
        for(auto it = um.begin(); it != um.end(); ++ it)
        {
            m.insert(make_pair(it->second,it->first));
            if(m.size() > k)
                m.erase(m.begin());
        }
        
        for(auto it = m.begin(); it != m.end(); ++ it)
            res.push_back(it->second);
        return res;
    }
};
