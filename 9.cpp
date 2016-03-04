class Solution {
public:
    bool isPalindrome(int x) {
           int i,n,s;
    long r;
    if(x < 0)
        return false;
        //x = -x;

    s = x;
    if( !x )
        return true;
    r = x;
    n = 0;
    while(r > 0)
    {
        n++;
        r = r / 10;
    }

    r = 0;
    for (i = 0; i < n; ++i)
    {
        r = r * 10 + x % 10;
        x /= 10;
        if(r > 0x7fffffff)
            return false;
    }
    if( r == s)
        return true;
    else
        return false;
    }
};
