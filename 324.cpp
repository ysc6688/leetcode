class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return ;
        
        sort(nums.begin(),nums.end());
        vector<int> res(size);
        
        int l = size >> 1;
        if(size % 2 == 0) -- l;
        int end = l;
        int r = size - 1;
        int i = 0;
        while(r > end)
        {
            res[i ++] = nums[l --];
            res[i ++] = nums[r --];
        }
        if(size & 1) res[i] = nums[0];
        nums = res;
    }
};
