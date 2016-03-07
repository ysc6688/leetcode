class Solution {
public:
    void reverseWord(string &s, int l, int r)
    {
        if( l >= r ) return ;
        while(l < r)
        {
            char t = s[l];
            s[l] = s[r];
            s[r] = t;
            ++ l;
            -- r;
        }
    }
    void reverseWords(string &s) {
        int size = s.size();
        if( !size ) return ;

        int l,r;
        
        l = 0;
        while(s[l] == ' ') ++ l;
        
        r = size - 1;
        while(s[r] == ' ') -- r;
        
        s = s.substr(l,r - l + 1);
        size = s.size();
        
        for(int i = 0; i < size - 1;)
        {
            if(s[i] == ' ' && s[i + 1] == ' ') s.erase(s.begin() + i + 1);
            else ++ i;
        }
        
        size = s.size();
        
        reverse(s.begin(),s.end());
        for(int i = 0; i < size; )
        {
            if(s[i] == ' ')
            {
                ++ i;
                continue;
            }
            else
            {
                l = r = i;
                while(s[r] != ' ' && r < size) ++ r;
                reverseWord(s,l,r - 1);
            }
            i = r + 1;
        }
    }
};
