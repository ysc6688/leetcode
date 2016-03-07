class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int min, cur, len;
        cur = len = 0;
        min = INT_MAX;
        int size = nums.size();
        for(int i = 0; i < size; ++ i)
        {
            cur += nums[i];
            ++ len;
            
            if(cur >= s)
            {
                int begin = i - len + 1;
                while(cur >= s)
                {
                    cur -= nums[begin++];
                    -- len;
                }
                min = std::min(min,len + 1);
            }
        }
        return min == INT_MAX ? 0 : min;
    }
};
