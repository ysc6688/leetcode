class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0 || amount <= 0) return 0;
        
        vector<int> dp(amount + 1,INT_MAX);
        dp[0] = 0;
        
        for(int i = 0; i < coins.size(); ++ i)
        {
            for(int j = coins[i]; j <= amount; ++ j)
            {
                int k = j - coins[i];
                if(dp[k] != INT_MAX) dp[j] = std::min(dp[j],dp[k] + 1);
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
