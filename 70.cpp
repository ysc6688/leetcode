class Solution {
public:
    int climbStairs(int n) {
    int res[n+1];
    for (int i = 1; i <= n; ++i)
    {
        if( i == 1 )
            res[i] = 1;
        else if( i == 2 )
            res[i] = 2;
        else
            res[i] = res[i-1] + res[i-2];
    }
    return res[n];
}
};
