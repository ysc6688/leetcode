class Solution {
public:
    int uniquePaths(int m, int n) {
        m -= 1;
        n -= 1;
        if( !m || !n )
            return 1;
        long long result = 1;
        int min = m <= n ? m : n;
        for(int i=m+n;i>m+n-min;--i)
            result *= i;
        for(int i=1;i<=min;++i)
            result /= i;
            
        return result;
    }
};
