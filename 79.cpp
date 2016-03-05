class Solution {
public:
    bool search(vector<vector<char>>& board, int x, int y, int num, string word, int v[500][500])
    {
        if( num == word.size() )
            return true;
        else
        {
            int m = board.size();
            int n = board[0].size();
            v[x][y] = 1;
            
            if(y != 0 && v[x][y-1]==0 && board[x][y-1] == word[num] && search(board,x,y-1,num+1,word,v) )
                return true;
            else if(y != n-1 && v[x][y+1]==0 && board[x][y+1] == word[num] && search(board,x,y+1,num+1,word,v) )
                return true;
            else if(x != 0 && v[x-1][y]==0 && board[x-1][y] == word[num] && search(board,x-1,y,num+1,word,v))
                return true;
            else if(x != m-1 && v[x+1][y]==0 && board[x+1][y] == word[num] && search(board,x+1,y,num+1,word,v))
                return true;
            
            v[x][y] = 0;
            return false;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if( word.size() == 0) return true;
        int num,i,j;
        int m = board.size();
        int n = board[0].size();
        bool result;
        
        if(m == 0 || n == 0)
            return false;
        
        result = false;
        
        int v[500][500];
        memset(v,0,sizeof(int)*m*100);

        for(i=0;i<m;++i)
            for(j=0;j<n;++j)
            {
                if(board[i][j] == word[0])
                {
                    num = 1;
                    memset(v,0,sizeof(int)*m*500);
                    result = search(board,i,j,num,word,v);
                    if( result )
                        return result;
                }
            }
        
        return result;
    }
};
