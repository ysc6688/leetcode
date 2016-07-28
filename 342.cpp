class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0) return false;
        
        int n = num;
        int count = 0;
        while(n)
        {
            ++ count;
            n = n & (n - 1);
        }
        
        if(count > 1) return false;
        for(long i = 1; i < 0x40000001; )
        {
            if(num & i) return true;
            i = (i << 2);
        }
        return false;
    }
};
