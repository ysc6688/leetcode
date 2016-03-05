class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int i,j;
        int size1,size2,size3;
        
        size1 = s1.size();
        size2 = s2.size();
        size3 = s3.size();
        
        if(size3 != size1 + size2) return false;
        
        bool dp[size1+1][size2+1] = { false };
        dp[0][0] = true;
        
        for(i=1;i<=size1;++i)
        {
            if(s1[i-1] == s3[i-1])
                dp[i][0] = true;
            else
                break;
        }
        for(j=1;j<=size2;++j)
        {
            if(s2[j-1] == s3[j-1])
                dp[0][j] = true;
            else
                break;
        }
        
        for(i=1;i<size1+1;++i)
            for(j=1;j<size2+1;++j)
            {
                dp[i][j] = (dp[i-1][j]&&s1[i-1]==s3[i+j-1]) || (dp[i][j-1]&&s2[j-1]==s3[i+j-1]);
            }
        return dp[size1][size2];
    }
};
