class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        if( !row ) return;
        int col = matrix[0].size();
        if( !col ) return;
        
        dp.resize(row);
        for(int i = 0; i < row; ++ i)
            dp[i].resize(col);
            
        int count = 0;
        for(int i = 0; i < col; ++ i)
        {
            count += matrix[0][i];
            dp[0][i] = count;
        }

        count = 0;
        for(int i = 0; i < row; ++ i)
        {
            count += matrix[i][0];
            dp[i][0] = count;
        }
        
        for(int i = 1; i < row; ++ i)
            for(int j = 0; j < col; ++ j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + matrix[i][j] - dp[i - 1][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 > row2 || col1 > col2) return 0;
        
        int res = dp[row2][col2];
        if(row1 == 0 && col1 == 0) return res;
        else if(row1 == 0)
        {
            res -= dp[row2][col1 - 1];
        }
        else if(col1 == 0)
        {
            res -= dp[row1 - 1][col2];
        }
        else
        {
            res = res - dp[row1 - 1][col2] - dp[row2][col1 - 1] + dp[row1 - 1][col1 - 1];
        }
        return res;
    }
private:
    vector<vector<int>> dp;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
