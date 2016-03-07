struct point{
    int x;
    int y;
    point(int i,int j) : x(i), y(j) {};
};


class Solution {
public:
    void fill(vector<vector<char>>& grid, int x, int y, int count)
    {
        int row = grid.size();
        int col = grid[0].size();
        
        char c = '1' + count;
        grid[x][y] = c;
        
        queue<point> q;
        q.push(point(x,y));
        
        while( !q.empty() )
        {
            int i,j;
            i = q.front().x;
            j = q.front().y;
            q.pop();

            if(j > 0 && grid[i][j - 1] == '1')
            {
                grid[i][j - 1] = c;
                q.push(point(i,j - 1));
            }
            if(j < col - 1 && grid[i][j + 1] == '1')
            {
                grid[i][j + 1] = c;
                q.push(point(i,j + 1));
            }
            if(i > 0 && grid[i - 1][j] == '1')
            {
                grid[i - 1][j] = c;
                q.push(point(i - 1,j));
            }
            if(i < row - 1 && grid[i + 1][j] == '1')
            {
                grid[i + 1][j] = c;
                q.push(point(i + 1,j));
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if( !row ) return 0;
        
        int col = grid[0].size();
        int count = 0;
        
        for(int i = 0; i < row; ++ i)
            for(int j = 0; j < col; ++ j)
            {
                if( grid[i][j] == '1')
                {
                    ++ count;
                    fill(grid,i,j,count);
                }
            }
        return count;
    }
};
