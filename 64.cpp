class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        
        int dp[m][n];
        memset(dp,0,sizeof(int)*m*n);
        dp[0][0] = grid[0][0];
        int i,j;
        for(i=0;i<m;++i)
            for(j=0;j<n;++j)
            {
                if(i==0 && j>0)
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                if(j==0 && i>0)
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                if(i>0 && j>0)
                    dp[i][j] = (dp[i-1][j] < dp[i][j-1]) ? dp[i-1][j] + grid[i][j] : dp[i][j-1] + grid[i][j];
            }
        return dp[m-1][n-1];
    }
};
