class Solution {
public:
    int reverse(int x) {
        char c[20];
        sprintf(c,"%d",x);
        string s(c);
        
        string rs;
        
        if(s[0] == '-') {
            rs += '-';
            s = s.substr(1);
        }
        std::reverse(s.begin(),s.end());
        
        int i;
        for(i = 0; i < s.size(); ++ i)
            if(s[i] != '0') break;
            
        s.substr(i);
        
        rs += s;
        
        long res = 0;
        
        i = 0;
        if(rs[i] == '-') ++ i;
        
        for(; i < rs.size(); ++ i)
        {
            res = res * 10 + rs[i] - '0';
            if(res > 0x7fffffff) return 0;
        }
        if(rs[0] == '-') res = -res;

        return res;
    }
};
