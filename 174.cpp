class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        if( !row ) return 1;
        int col = dungeon[0].size();
        if( !col ) return 1;
        
        int dp[row][col];
        
        memset(dp,0,sizeof(int) * row * col);
        
        dp[row - 1][col - 1] = dungeon[row - 1][col - 1];
        
        for(int i = row - 2; i >= 0; -- i)
            dp[i][col - 1] = std::min(dungeon[i][col - 1], dp[i + 1][col - 1] + dungeon[i][col - 1]);
            
        for(int i = col - 2; i >= 0; -- i)
            dp[row - 1][i] = std::min(dungeon[row - 1][i], dp[row - 1][i + 1] + dungeon[row - 1][i]);
            
        for(int i = row - 2; i >= 0; -- i)
            for(int j = col - 2; j >= 0; -- j)
            {
                int right = std::min(dungeon[i][j] + dp[i][j + 1], dungeon[i][j]);
                int down = std::min(dungeon[i][j] + dp[i + 1][j], dungeon[i][j]);
                dp[i][j] = std::max(right,down);
            }
                
        if(dp[0][0] >= 0) return 1;
        else return -(dp[0][0] - 1);
    }
};
