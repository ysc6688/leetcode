class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        if(size < 2) return true;
        
        //transform(s.begin(),s.end(),s.begin(),::tolower);
        
        int l = 0, r = size - 1;
        while(l < r)
        {
            if( s[l] < '0' || (s[l] > '9' && s[l] < 'A') || (s[l] > 'Z' && s[l] < 'a') || s[l] > 'z' )
            {
                ++l;
                continue;
            }
            if( s[r] < '0' || (s[r] > '9' && s[r] < 'A') || (s[r] > 'Z' && s[r] < 'a') || s[r] > 'z' )
            {
                --r;
                continue;
            }
            int j = abs(s[l] - s[r]);
            if(j == 0 || j == 32)
            {
                ++l;
                --r;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
