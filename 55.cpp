class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i,max;
        max = 0;
        for(i=0;i<nums.size();++i)
        {
            if(i > max)
                return false;
            if(max < i + nums[i])
                max = i + nums[i];
            if(max >= nums.size()-1)
                return true;
        }
        if(max < nums.size()-1)
            return false;
    }
};
