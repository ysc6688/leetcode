class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i,pivot,left,right;
        std::map<int, int> map;

        for(i=0;i<nums.size();)
        {
            if(nums[i] <= 0)
                nums.erase(nums.begin() + i);
            else
                ++i;
        }
        if(nums.size() == 0)
            return 1;

        for(i=0;i<nums.size();++i)
        {
            if(map.count(nums[i]) == 0)
                map[nums[i]] = 1;
            else
                map[nums[i]]++;
        }
        for(i=0;i<nums.size();)
        {
            if(map[nums[i]] > 1)
            {
                map[nums[i]]--;
                nums.erase(nums.begin() + i);
            }
            else
                ++i;
        }

        left = 0;
        right = nums.size() - 1;
        while(left < right)
        {
            pivot = qsort(nums, left, right);
            if(pivot  == nums[pivot] - 1)
                left = pivot + 1;
            else
                right = pivot - 1;
        }
        if(left == nums[left] - 1)
            return left + 2;
        else
            return left + 1;
    }
    int qsort(vector<int>& nums,int left,int right)
    {
        int pivot = nums[left];
        while(left < right)
        {
            while(nums[right] >= pivot && left < right) --right;
            nums[left] = nums[right];
            while(nums[left] <= pivot && left < right) ++left;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
};
