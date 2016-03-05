class Solution {
public:
    bool linear(vector<int>& nums, int l, int r, int target)
    {
        for(int i = l; i<= r; ++ i)
            if(nums[i] == target) return true;
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if( !size ) return false;
        if( size == 1 ) return nums[0] == target;
        
        int l,r,m;
        l = 0;
        r = size - 1;
        
        while(l <= r)
        {
            m = (l + r) >> 1;
            if( nums[m] == target ) return true;
            
            if(nums[m] == nums[l] || nums[m] == nums[r]) return linear(nums,l,r,target);
            
            if( nums[m] > nums[r] )
            {
                if( target >= nums[l] && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            else
            {
                if( target > nums[m] && target <= nums[r] )
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return false;
    }
};
