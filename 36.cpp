class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int l[10] = {0}, c[10] = {0};
        int i,j;
        for(i=0;i<9;++i)
        {
            for(j=0;j<9;++j)
            {
               if(board[i][j] != '.' && l[board[i][j]-'0'] == 0)
                    ++l[board[i][j]-'0'];
                else if(board[i][j] != '.')
                    return false;

                if(board[j][i] != '.' && c[board[j][i]-'0'] == 0)
                    ++c[board[j][i]-'0'];
                else if(board[j][i] != '.')
                    return false;
            }
            memset(l,0,sizeof(int)*10);
            memset(c,0,sizeof(int)*10);
        }
        int k,m;
        memset(l,0,sizeof(int)*10);
        for(i=0;i<3;++i)
            for(j=0;j<3;++j)
            {
                for(k=0;k<3;++k)
                    for(m=0;m<3;++m)
                    {
                        if(board[3*i+k][3*j+m] == '.')
                            continue;
                        else if(l[board[3*i+k][3*j+m]-'0'] == 0 )
                            ++l[board[3*i+k][3*j+m]-'0'];
                        else
                            return false;
                    }
                memset(l,0,sizeof(int)*10);
            }
            return true;
    }
};
