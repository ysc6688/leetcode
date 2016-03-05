class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0 || obstacleGrid[0][0] == 1)
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int i,j;
        int a[m][n];
        memset(a,0,sizeof(int)*m*n);
        a[0][0] = 1;
        for(i=0;i<m;++i)
            for(j=0;j<n;++j)
            {
                if(obstacleGrid[i][j] == 1)
                    continue;
                if(i==0 && j>0)
                    a[i][j] = a[i][j-1];
                else if(i>0 && j==0)
                    a[i][j] = a[i-1][j];
                else if(i>0 && j>0)
                    a[i][j] = a[i-1][j] + a[i][j-1];
            }
        
        return a[m-1][n-1];
    }
};
