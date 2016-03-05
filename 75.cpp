class Solution {
public:
    void sortColors(vector<int>& nums) {
        int color[3] = { 0 };
        int i,end,size;
        size = nums.size();
        for(i=0;i<size;++i)
            ++color[nums[i]];
        for(i=0;i<color[0];++i)
            nums[i] = 0;
        end = color[0] + color[1];
        for(i=color[0];i<end;++i)
            nums[i] = 1;
        for(i=end;i<size;++i)
            nums[i] = 2;
    }
};
