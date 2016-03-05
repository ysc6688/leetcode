class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        int *a = new int[n];
        int i = 0,j;
        bool ok;
        
        vector<vector<string> > result;
        vector<string> s;
        string line = "";
        
        if(n==0) return result;
        
        for(j=0;j<n;++j)
            line += ".";
        
        memset(a,0,sizeof(int)*n);
        while(i <= n)
        {
            if(i == n)
            {
                if(--i >= 0) 
                {
                    ++a[i];
                    result.push_back(s);
                    s.pop_back();
                    continue;
                }
                else break;
            }
            if(a[i] == n)
            {
                a[i] = 0;
                if(--i >= 0)
                {
                    s.pop_back();
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
            if(ok) {
                string l = line;
                l[a[i]] = 'Q';
                s.push_back(l);
                ++i;
            }
            else ++a[i];
        }
        
        delete[] a;
        return result;
    }
};
