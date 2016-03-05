class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if( !size ) return 0;
        if( s[0] == '0') return 0;
        
        int dp[size+1] = { 0 };
        
        for(int i=1;i<=size;++i)
        {
            if(i == 1)
            {
                if(s[i-1] != '0')
                    dp[i] = 1;
            }
            else if(i == 2) {
                if(s[i-1] != '0')
                    dp[i] = dp[i-1];
                int l = (s[i-2] - '0') * 10 + s[i-1] - '0';
                if(l <= 26 && l > 0)
                    dp[i] += 1;
            }
            else
            {
                if(s[i-1] != '0')
                    dp[i] = dp[i-1];
                if(s[i-2] != '0') {
                    int l = (s[i-2] - '0') * 10 + s[i-1] - '0';
                    if(l <= 26 && l > 0)
                        dp[i] += dp[i-2];
                }
            }
        }
        return dp[size];
    }
};
