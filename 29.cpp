class Solution {
public:
    int divide(int dividend, int divisor) {
        long q,flag = 1;
        long dd = dividend, dr = divisor;
        long r,t;
        q = 0;
        if( !dr )
            return 0x7fffffff;
        if( dd < 0)
        {
            dd = -dd;
            flag = -flag;
        }
        if( dr < 0)
        {
            dr = -dr;
            flag = -flag;
        }
        if(dd < dr)
            return 0;
        if(dd == dr)
            return (flag == 1) ? 1 : -1;
        while(dd >= dr)
        {
            r = dr;
            int count = 0;
            while(r <= dd)
            {
                ++count;
                r = r << 1;
            }
            t = 1;
            for (int i = 0; i < count-1; ++i)
                t = t << 1;
            q += t;
            if(q > 0x7fffffff && flag == 1)
                return 0x7fffffff;
            dd -= (r >> 1);
        }
        return (flag == 1) ? q : -q;
    }
};
