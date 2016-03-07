class Solution {
public:
    void r(vector<int>& nums, int l, int r)
    {
        if( l >= r ) return ;
        while(l < r)
        {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            ++ l;
            -- r;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if( !size || k <= 0) return ;
        k = k % size;
        if( !k ) return ;
        
        r(nums, 0 ,size - k - 1);
        r(nums, size - k, size - 1);
        r(nums, 0, size - 1);
    }
};
