class Solution {
public:
    string countAndSay(int n) {
        string s("1");
        for(int i=0;i<n-1;++i)
            s = gen(s);
        return s;
    }
    
    string gen(string ns)
    {
        int i,n;
        string r = "";
        char c,last;
        
        n = 1;
        last = ns[0];
        for(i=1;i<ns.size();++i)
        {
            c = ns[i];
            if(c == last)
            {
                ++n;
            }
            else
            {
                char add[20];
                sprintf(add,"%d%c",n,last);
                r += add;
                n = 1;
                last = c;
            }
        }
        char add[20];
        sprintf(add,"%d%c",n,last);
        r += add;
        return r;
    }
};
