class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int len = nums.size();
        if(n <= 0) return 0;
        
        int res = 0;
        long long max = 0;
        int index = 0;
        
        while(max < n)
        {
            if(index >= len || nums[index] > max + 1)
            {
                ++ res;
                max += (max + 1);
            }
            else
            {
                max += nums[index];
                ++ index;
            }
        }
        
        return res;
    }
};
