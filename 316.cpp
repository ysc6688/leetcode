class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        int size = s.size();
        if( !size ) return res;
        int hash[26] = { 0 };
        
        for(int i = 0; i < size; ++ i)
            hash[s[i] - 'a'] ++;
            
        int minpos = 0;

        for(int i = 0; i < size; ++ i)
        {
            -- hash[s[i] - 'a'];
            if(s[i] < s[minpos]) minpos = i;
            if(hash[s[i] - 'a'] == 0) break;
        }
        
        res += s[minpos];
        
        string tmpstr;
        for(int i = minpos; i < size; ++ i)
            if(s[i] != s[minpos]) tmpstr += s[i];
        
        res += removeDuplicateLetters(tmpstr);
            
        return res;
    }
}
