class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        //if(size == 0) return 0;
        int res = 0;
        for(int i = 0; i < size; ++ i)
            res ^= nums[i];
        
        return res;
    }
};
