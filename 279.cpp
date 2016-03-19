class Solution {
public:
    int numSquares(int n) {
        vector<int> v(n + 1,0);
        
        for(int i = 1; i * i <= n; ++ i)
            v[i * i] = 1;
            
        if(v[n] == 1) return 1;
        
        for(int i = 2; i <= n; ++ i)
        {
            if(v[i] == 1) continue;
            int min = INT_MAX;
            for(int j = 1; j * j < i; ++ j)
            {
                int k = j * j;
                min = std::min(min, 1 + v[i - k]);
            }
            v[i] = min;
        }
        return v[n];
    }
};
