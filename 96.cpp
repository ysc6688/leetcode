class Solution {
public:
    int numTrees(int n) {
        if(n <= 1) return n;
        
        int num[n+1];
        num[0] = 1;
        num[1] = 1;
        
        for(int i=2;i<=n;++i)
        {
            int j = i - 1;
            int x = 0;
            for(int k=0;k<=j;++k)
            {
                x += num[k] * num[j-k];
            }
            num[i] = x;
        }
        return num[n];
    }
};
