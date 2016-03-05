class Solution {
public:
    int mySqrt(int x) {
        if( !x ) return 0;
        int l,r,m;
        int b = 46339;
        
        l = 0;
        r = b;
        
        while(l <= r)
        {
            m = (r + l) / 2;
            int e = m * m;
            if( e == x)
                return m;
            else if( e > x)
            {
                int t = m - 1;
                if( t*t < x)
                    return t;
                else
                    r = m - 1;
            }
            else
            {
                int t = m + 1;
                if( t*t > x)
                    return m;
                else
                    l = m + 1;
            }
        }
        return l;
    }
};
