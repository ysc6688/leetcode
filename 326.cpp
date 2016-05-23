class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        long x = 1;
        while(n != x)
        {
            if(x > n) return false;
            x *= 3;
        }
        
        return n == x;
    }
};
