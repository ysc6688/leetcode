class Solution {
public:
    int compute(vector<vector<int>>& board, int x, int y)
    {
        int m = board.size();
        int n = board[0].size();
        
        int count = 0;
        //up three
        if(x > 0)
        {
            if(y > 0 && (board[x - 1][y - 1] == 1 || board[x - 1][y - 1] == 2)) ++ count;
            if(board[x - 1][y] == 1 || board[x - 1][y] == 2) ++ count;
            if(y < n - 1 && (board[x - 1][y + 1] == 1 || board[x - 1][y + 1] == 2)) ++ count;
        }
        //left
        if(y > 0 && (board[x][y - 1] == 1 || board[x][y - 1] == 2)) ++ count;
        //right
        if(y < n - 1 && board[x][y + 1] == 1) ++ count;
        //down
        if(x < m - 1)
        {
            if(y > 0 && board[x + 1][y - 1] == 1) ++ count;
            if(board[x + 1][y] == 1) ++ count;
            if(y < n - 1 && board[x + 1][y + 1] == 1) ++ count;
        }
        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if( !m ) return ;
        
        int n = board[0].size();
        if( !n ) return ;
        
        for(int i = 0; i < m; ++ i)
            for(int j = 0; j < n; ++ j)
            {
                int count = compute(board,i,j);
                if(board[i][j] && (count < 2 || count > 3)) board[i][j] = 2;
                else if(board[i][j] == 0 && count == 3) board[i][j] = 3;
            }
            
        for(int i = 0; i < m; ++ i)
            for(int j = 0; j < n; ++ j)
            {
                if(board[i][j] == 2) board[i][j] = 0;
                else if(board[i][j] == 3) board[i][j] = 1;
            }
    }
};
