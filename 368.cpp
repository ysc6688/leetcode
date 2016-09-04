class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        if( !len ) return res;
        
        sort(nums.begin(), nums.end());
        
        vector<int> dp(len);
        dp[0] = 1;
        
        int max = 1, index = 0;

        for(int i = 1; i < len; ++ i)
        {
            for(int j = i - 1; j >= 0; -- j)
            {
                if(nums[i] % nums[j] == 0)
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                    if(dp[i] > max)
                    {
                        max = dp[i];
                        index = i;
                    }
                }
            }
        }
        
        for(int i = index; i >= 0; -- i)
        {
            if(nums[index] % nums[i] == 0 && dp[i] == max)
            {
                res.push_back(nums[i]);
                -- max;
            }
        }
        
        return res;
    }
};
