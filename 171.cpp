class Solution {
public:
    int titleToNumber(string s) {
        int size = s.size();
        if( !size ) return 0;
        
        int res = 0;
        
        for(int i = 0; i < size; ++ i)
        {
            res *= 26;
            res = res + s[i] - 'A' + 1;
        }
        
        return res;
    }
};
