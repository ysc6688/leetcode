class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int size = s.size();
        if(size == 0) return true;
        
        vector<int> dp(size + 1);
        dp[0] = 1;
        
        for(int i = 1; i <= size; ++ i)
        {
            for(int j = i - 1; j >= 0; -- j)
            {
                if(dp[j] && wordDict.find(s.substr(j,i - j)) != wordDict.end())
                {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[size] == 0 ? false : true;
    }
};
