class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        int si[26] = { 0 };
        int ti[26] = { 0 };
        
        int size = s.size();
        
        for(int i = 0; i < size; ++ i)
        {
            si[s[i] - 'a'] ++;
            ti[t[i] - 'a'] ++;
        }
        
        for(int i = 0; i < 26; ++ i)
            if(si[i] != ti[i]) return false;
            
        return true;
    }
};
