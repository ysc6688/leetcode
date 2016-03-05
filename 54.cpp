class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if( !m ) return res;
        int n = matrix[0].size();
        if( !n ) return res;
        
        int i,l = (m > n) ? n : m;
        
        for(i=0;i<l/2;++i)
        {
            for(int j=i;j<n-i;++j)
                res.push_back(matrix[i][j]);
            for(int j=i+1;j<m-i;++j)
                res.push_back(matrix[j][n-1-i]);
            for(int j=n-2-i;j>=i;--j)
                res.push_back(matrix[m-1-i][j]);
            for(int j=m-2-i;j>i;--j)
                res.push_back(matrix[j][i]);
        }
        if(m <= n && l%2 == 1)
        {
            for(int j=i;j<n-i;++j)
                res.push_back(matrix[i][j]);
        }
        else if(m > n && l%2 == 1)
        {
            for(int j=i;j<m-i;++j)
                res.push_back(matrix[j][i]);
        }
        return res;
    }
};
