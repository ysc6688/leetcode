class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if( !row ) return 0;
        
        int col = matrix[0].size();
        if( !col ) return 0;
        
        int dp[row][col];
        memset(dp,0,sizeof(int)*row*col);
        
        int max = 0;
        for(int i = 0; i < col; ++ i)
        {
            dp[0][i] = matrix[0][i] - '0';
            max += dp[0][i];
        }
        for(int i = 0; i < row; ++ i)
        {
            dp[i][0] = matrix[i][0] - '0';
            max += dp[i][0];
        }
        
        max = (max > 0) ? 1 : 0;
            
        for(int i = 1; i < row; ++ i)
            for(int j = 1; j < col; ++ j)
            {
                if(matrix[i][j] == '1')
                {
                    int min = std::min(dp[i - 1][j],std::min(dp[i][j - 1],dp[i - 1][j - 1]));
                    dp[i][j] = min + 1;
                    max = std::max(dp[i][j],max);
                }
            }
        return max * max;
    }
};
