class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) return false;
        
        int arr[3];
        arr[0] = arr[1] = arr[2] = -1;
        int count = 0;
        
        for(int i = 0; i < len; ++ i)
        {
            if(count == 0)
            {
                arr[0] = nums[i];
                ++ count;
            }
            else if(count == 1)
            {
                if(arr[0] >= nums[i])
                    arr[0] = nums[i];
                else
                {
                    arr[1] = nums[i];
                    ++ count;
                }
            }
            else
            {
                if(nums[i] > arr[1]) return true;
                else if(nums[i] <= arr[1] && nums[i] > arr[0])
                    arr[1] = nums[i];
                else
                    arr[0] = nums[i];
            }
        }
        
        return false;
    }
};
