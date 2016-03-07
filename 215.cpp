class Solution {
public:
    void modifyHeap(vector<int>& nums, int index, int k)
    {
        int lc = 2*index+1;
        int rc = lc+1;
        if(lc>=k) return;

        int minv = nums[index];
        int minindex = index;
        if(lc<k && nums[lc]<minv)
        {
            minv = nums[lc];
            minindex = lc;
        }
        if(rc<k && nums[rc]<minv)
        {
            minv = nums[rc];
            minindex = rc;
        }
        if(minindex!=index)
        {
            swap(nums[minindex],nums[index]);
            modifyHeap(nums,minindex,k);
        }
    }
    void buildHeap(vector<int>& nums, int k)
    {
        int x = k/2-1;
        for(int i = x;i>=0;--i)
        {
            modifyHeap(nums,i,k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int size ;
        if((size=nums.size()) == 0) return 0;
        if(size == 1)return nums[0];
        buildHeap(nums,k);
        for(int i = k;i<size;++i)
        {
            if(nums[i]>nums[0])
            {
                swap(nums[i],nums[0]);
                modifyHeap(nums,0,k);
            }

        }

        return nums[0];
    }
};
