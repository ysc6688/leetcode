class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i,j;
        int m = matrix.size();
        int n = matrix[0].size();
        int r[m] = { 0 };
        int c[n] = { 0 };
        for(i=0;i<m;++i)
            for(j=0;j<n;++j)
            {
                if( !matrix[i][j] )
                {
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        for(i=0;i<m;++i)
        {
            if(r[i])
            {
                for(j=0;j<n;++j)
                    matrix[i][j] = 0;
            }
        }
        for(i=0;i<n;++i)
        {
            if(c[i])
            {
                for(j=0;j<m;++j)
                    matrix[j][i] = 0;
            }
        }
    }
};
