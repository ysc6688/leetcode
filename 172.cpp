class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        long long five = 5;
        long long lln = n;
        
        while( 1 )
        {
            long long d = lln / five;
            if( d )
            {
                res += d;
                five *= 5;
            }
            else break;
        }
        return res;
    }
};
