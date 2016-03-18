class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if( !size ) return 0;
        
        int l,r,m;
        l = 0;
        r = size - 1;
        
        while(l <= r)
        {
            m = l + ((r - l) >> 1);
            if(size - m == citations[m]) return size - m;
            else if(size - m > citations[m]) l = m + 1;
            else r = m - 1;
        }
        
        return size - l;
    }
};
