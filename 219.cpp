class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int size = nums.size();
        
        for(int i = 0; i < size; ++ i)
        {
            unordered_map<int,int>::iterator it = m.find(nums[i]);
            if(it != m.end() && i - it->second <= k) return true;
            else if(it != m.end()) it->second = i;
            else m.insert(make_pair(nums[i],i));
        }
        return false;
    }
};
