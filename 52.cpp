class Solution {
public:
    int totalNQueens(int n) {
        if (n == 0) return 0;
        int *a = new int[n];
        int i = 0,j,count = 0;
        bool ok;
        
        memset(a,0,sizeof(int)*n);
        while(i <= n)
        {
            if(i == n)
            {
                ++count;
                if(--i >= 0) 
                {
                    ++a[i];
                    continue;
                }
                else break;
            }
            if(a[i] == n)
            {
                a[i] = 0;
                if(--i >= 0)
                {
                    ++a[i];
                    continue;
                }
                else break;
            }
            ok = true;
            for(j=0;j<i;++j)
            {
                if(a[j] == a[i] || i - j == abs(a[i] - a[j]))
                {
                    ok = false;
                    break;
                }
            }
            if(ok) ++i;
            else ++a[i];
        }
        
        delete[] a;
        return count;
    }
};
