class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if( size == 1 ) return 0;
        
        int l, r, m;
        l = 0;
        r = size - 1;
        while( l <= r )
        {
            if( r - l < 2)
                return nums[l] > nums[r] ? l : r;
            m = (l + r) >> 1;
            
            if( !m && nums[m] > nums[m + 1] ) return m;
            if( m == size - 1 && nums[m] > nums[m - 1] ) return m;
            
            if( nums[m] > nums[m - 1] && nums[m] > nums[m + 1] ) return m;
            
            if( nums[m] < nums[m - 1] )
                r = m;
            else
                l = m;
        }
        return l;
    }
};
