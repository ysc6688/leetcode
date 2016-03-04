class Solution {
public:
    int searchInsert(vector<int>& A, int target) {
        int size = A.size();
        if( !size ) return 0;
        
        int l,m,r;
        l = 0;
        r = size - 1;
        
        while(l <= r)
        {
            m = (l + r) >> 1;
            if( A[m] == target ) return m;
            else if(A[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};
