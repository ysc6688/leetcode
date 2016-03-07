class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if( !size ) return 0;
        if(size == 1) return nums[0];
        
        int dp[size] = { 0 };
        int max = -1;
        
        dp[0] = nums[0];
        dp[1] = std::max(nums[0],nums[1]);
        
        for(int i = 2; i < size - 1; ++ i)
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
            
        max = dp[size - 2];
        
        dp[size - 1] = nums[size - 1];
        dp[size - 2] = std::max(nums[size - 1], nums[size - 2]);
        
        for(int i = size - 3; i > 0; -- i)
            dp[i] = std::max(dp[i + 1], dp[i + 2] + nums[i]);
            
        max = std::max(max,dp[1]);
        
        return max;
        
        
    }
};
