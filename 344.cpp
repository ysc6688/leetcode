class Solution {
public:
    string reverseString(string s) {
        int size = s.size();
        if( size < 2) return s;
        
        int l = 0;
        int r = size - 1;
        while(l < r)
        {
            char t = s[l];
            s[l] = s[r];
            s[r] = t;
            
            ++ l;
            -- r;
        }
        return s;
    }
};
