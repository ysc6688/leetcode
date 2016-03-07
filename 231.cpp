class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == -2147483648) return false;
        int count = 0;
        while( n )
        {
            ++ count;
            n = n & (n - 1);
            if( count > 1 ) return false;
        }
        return count == 1 ? true : false;
    }
};
