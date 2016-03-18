// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n < 2) return n;
        
        int l, r, m;
        
        l = 1;
        r = n;
        
        while(l < r)
        {
            m = l + ( (r - l) >> 1);
            if( isBadVersion(m) ) r = m;
            else l = m + 1;
        }
        
        return l;
    }
};
