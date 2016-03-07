class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int count = 1;
        int n = nums[0];
        for(int i = 1; i < size; ++ i)
        {
            if(nums[i] == n)
                ++ count;
            else if( --count < 0 )
            {
                count = 1;
                n = nums[i];
            }
        }
        return n;
    }
};
