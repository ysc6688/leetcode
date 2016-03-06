class Solution {
public:
    void bfs(vector<vector<char>>& board,int x,int y,int row,int col)
    {
        queue<pair<int,int>> q;
        q.push(make_pair(x,y));
        board[x][y] = 'E';
        while( !q.empty() )
        {
            pair<int,int> p = q.front();
            q.pop();
            x = p.first;
            y = p.second;
            //left
            int j = y - 1;
            while(j >= 0)
            {
                if(board[x][j] == 'O')
                {
                    board[x][j] = 'E';
                    q.push(make_pair(x,j));
                    --j;
                }
                else break;
            }
            //right
            j = y + 1;
            while(j < col)
            {
                if(board[x][j] == 'O')
                {
                    board[x][j] = 'E';
                    q.push(make_pair(x,j));
                    ++j;
                }
                else break;
            }
            //up
            int i = x - 1;
            while(i >= 0)
            {
                if(board[i][y] == 'O')
                {
                    board[i][y] = 'E';
                    q.push(make_pair(i,y));
                    --i;
                }
                else break;
            }
            //down
            i = x + 1;
            while(i < row)
            {
                if(board[i][y] == 'O')
                {
                    board[i][y] = 'E';
                    q.push(make_pair(i,y));
                    ++i;
                }
                else break;
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if( !row ) return ;
        int col = board[0].size();
        if( !col ) return ;
        
        for(int i = 0; i < row; ++ i)
        {
            if(board[i][0] == 'O') bfs(board,i,0,row,col);
            if(board[i][col - 1] == 'O') bfs(board,i,col - 1,row,col);
        }
        for(int j = 0; j < col; ++ j)
        {
            if(board[0][j] == 'O') bfs(board,0,j,row,col);
            if(board[row - 1][j] == 'O') bfs(board,row - 1,j,row,col);
        }

        for(int i = 0; i < row; ++ i)
            for(int j = 0; j < col; ++ j)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'E') board[i][j] = 'O';
            }
    }
};
