class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() <= 1)
            return 0;
        int i=0,*a,l;
        while(s[i]==')')
            i++;
        string ss = s.substr(i);
        if(ss.length() <= 1)
            return 0;
        vector<int> v;
        l = ss.length();
        a = new int[l];
        memset(a,0,sizeof(int)*l);
        for(i=0;i<l;++i)
        {
            if(ss[i] == '(')
                v.push_back(i);
            else if( v.size() )
            {
                int p = v.back();
                v.pop_back();
                a[i] = 1;
                a[p] = 1;
            }
        }
        int ll,max;
        ll = 0;
        max = -1;
        for(i=0;i<l;++i)
        {
            if(a[i] == 0)
            {
                if(ll > max)
                    max = ll;
                ll = 0;
            }
            else
            {
                ++ll;
            }
        }
        if(max<ll)
            max = ll;
        delete[] a;
        return max;
    }
};
