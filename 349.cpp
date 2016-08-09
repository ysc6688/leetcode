class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        vector<int> res;
        if(!len1 || !len2) return res;
        
        set<int> s1;
        set<int> s2;
        
        for(int i = 0; i < len1; ++ i)
            s1.insert(nums1[i]);
        
        for(int i = 0; i < len2; ++ i)
            s2.insert(nums2[i]);
        
        res.resize(std::max(s1.size(),s2.size()));
        vector<int>::iterator retEndPos = set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),res.begin());
        res.resize(retEndPos - res.begin());
            
        return res;
    }
};
