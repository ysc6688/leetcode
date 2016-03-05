class Solution {
public:
    int minDistance(string word1, string word2) {
        if( !word1.size() ) return word2.size();
        if( !word2.size() ) return word1.size();
        
        int m = word1.size() + 1;
        int n = word2.size() + 1;
        
        int d[m][n];
        int i,j;
        
        for(i=0;i<m;i++)
            d[i][0] = i;
        for(i=0;i<n;i++)
            d[0][i] = i;
        
        int size1 = m - 1;
        int size2 = n - 1;
        for(i=0;i<size1;++i)
            for(j=0;j<size2;++j)
            {
                if(word1[i] == word2[j])
                    d[i+1][j+1] = d[i][j];
                else
                {
                    int a[3];
                    a[0] = d[i][j] + 1;
                    a[1] = d[i][j+1] + 1;
                    a[2] = d[i+1][j] + 1;
                    int min = a[0];
                    if( min > a[1] ) min = a[1];
                    if( min > a[2] ) min = a[2];
                    d[i+1][j+1] = min;
                }
            }
        return d[m-1][n-1];
    }
};
