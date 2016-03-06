class Solution {
public:
    int minCut(string s) {
        int size = s.size();
        if(size < 2) return 0;
        
        bool isp[size][size];
        memset(isp,false,size * size * sizeof(bool));
        
        int cut[size + 1];
        for(int i = 0; i < size; ++ i)
            cut[i] = INT_MAX;
        cut[size] = -1;
        
        for(int i = size - 1; i >= 0; -- i)
            for(int j = i; j < size; ++ j)
            {
                if(s[i] == s[j] && (j - i < 2 || isp[i + 1][j - 1]) )
                {
                    isp[i][j] = true;
                    if( cut[i] > cut[j+1] + 1 )
                        cut[i] = cut[j + 1] + 1;
                }
            }
            
        return cut[0];
    }
};
