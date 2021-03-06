class Solution {
public:
    int linear(vector<int>& nums, int l, int r)
    {
        if( l == r ) return nums[l];
        int min = nums[r];
        for(int i = l; i < r; ++ i)
            if(min > nums[i]) min = nums[i];
        
        return min;
    }
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if( !size ) return 0;
        if( size == 1 ) return nums[0];
        
        int l,m,r;
        l = 0;
        r = size - 1;
        
        while(l < r)
        {
            if( nums[l] < nums[r] ) return nums[l];
            if( r - l < 2 ) 
                return nums[l] < nums[r] ? nums[l] : nums[r];
            
            m = (l + r) >> 1;
            
            if( nums[m] == nums[l] && nums[m] == nums[r])
                return linear(nums,l,r);
            
            if(nums[m] > nums[r])
                l = m;
            else
                r = m;
        }
        return nums[l];
    }
};
