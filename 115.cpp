class Solution {
public:
    int numDistinct(string s, string t) {
        int sz = s.size();
        int tz = t.size();
        if(sz == 0) return 0;
        if(tz == 0) return 1;
        
        sz += 1;
        tz += 1;
        
        int dp[sz][tz];
        
        memset(dp,0,sizeof(int) * sz * tz);
        for(int i=0;i<sz;++i)
            dp[i][0] = 1;
            
        for(int i = 1; i < sz; ++i)
            for(int j = 1; j < tz; ++j)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
            
        return dp[sz-1][tz-1];
    }
};
