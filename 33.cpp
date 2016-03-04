class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if( !size ) return -1;
        
        int l, m, r;
        l = 0;
        r = size - 1;
        while(l <= r)
        {
            m = (l + r) >> 1;
            if(nums[m] == target) return m;
            else if( nums[m] >= nums[r] )
            {
                if(target <= nums[m] && target >= nums[l])
                    r = m - 1;
                else
                    l = m - 1;
            }
            else
            {
                if(target <= nums[r] && target >= nums[m])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return -1;
    }

};

