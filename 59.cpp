class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res;
        if( !n ) return res;
        
        int i,m = 1;
        res.resize(n);
        for(i=0;i<n;++i)
            res[i].resize(n);
        for(i=0;i<n/2;++i)
        {
            for(int j=i;j<n-i;++j)
                res[i][j] = m++;
            for(int j=i+1;j<n-i;++j)
                res[j][n-1-i] = m++;
            for(int j=n-2-i;j>=i;--j)
                res[n-1-i][j] = m++;
            for(int j=n-2-i;j>i;--j)
                res[j][i] = m++;
        }
        if(n % 2 == 1)
            res[i][i] = m;
        return res;
    }
};
