class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if( !size ) return 0;
        if( size == 1 ) return nums[0];
        
        int dp[size] = { 0 };
        
        dp[0] = nums[0];
        dp[1] = std::max(nums[0],nums[1]);
        
        for(int i = 2; i < size; ++ i)
        {
            dp[i] = std::max(dp[i - 2] + nums[i],dp[i - 1]);
        }
        return dp[size - 1];
    }
};
