class Solution {
public:
    double myPow(double x, int n) {
        if( !n ) return 1.0;
        bool isneg = false;
        if(n < 0) {
            isneg = true;
            n = -n;
        }
        long t = 1;
        int count = 0;
        double p = x;
        while(t*2 < n) {
            t *= 2;
            count++;
        }
        for(int i=0;i<count;++i)
            p = p * p;
        p = p * myPow(x,n-t);
        if( isneg )
            return 1.0 / p;
        else
            return p;
    }
};
