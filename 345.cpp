class Solution {
public:
    string reverseVowels(string s) {
        int len = s.size();
        if(len < 2) return s;
        
        int l = 0, r = len - 1;
        int hash[128] = { 0 };
        hash['a'] = 1;
        hash['e'] = 1;
        hash['i'] = 1;
        hash['o'] = 1;
        hash['u'] = 1;
        
        hash['A'] = 1;
        hash['E'] = 1;
        hash['I'] = 1;
        hash['O'] = 1;
        hash['U'] = 1;
        
        
        while(l < r)
        {
            while(l < len && hash[s[l]] == 0) ++ l;
            while(r >= 0 && hash[s[r]] == 0) -- r;
            if(l < len && r >= 0 && l < r)
            {
                char temp = s[l];
                s[l] = s[r];
                s[r] = temp;
                ++ l;
                -- r;
            }
        }
        
        return s;
    }
};
