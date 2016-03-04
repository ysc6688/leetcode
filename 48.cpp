class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return;
        int m = matrix.size(), n = matrix[0].size();
        
        int max = (m > n) ? m : n;
        
        matrix.resize(max);
        
        for(int i=0;i<m;++i)
            matrix[i].resize(max);
        
        for(int i=0;i<m;++i)
            for(int j=i+1;j<n;++j)
            {
                if(matrix[i][j] == matrix[j][i]) continue;
                matrix[i][j] = matrix[i][j] ^ matrix[j][i];
                matrix[j][i] = matrix[i][j] ^ matrix[j][i];
                matrix[i][j] = matrix[i][j] ^ matrix[j][i];
            }
        matrix.resize(n);
        for(int i=0;i<m;++i)
            matrix[i].resize(m);
            
        for(int i=0;i<n;++i)
            for(int j=0;j<m/2;++j)
            {
                if(matrix[i][j] == matrix[i][m-1-j]) continue;
                matrix[i][j] = matrix[i][j] ^ matrix[i][m-1-j];
                matrix[i][m-1-j] = matrix[i][j] ^ matrix[i][m-1-j];
                matrix[i][j] = matrix[i][j] ^ matrix[i][m-1-j];
            }
    }
};
