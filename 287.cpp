class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        if( !size ) return 0;
        
        int l,r,m;
        
        l = 1;
        r = size - 1;
        
        while(l < r)
        {
            int m = l + ((r - l) >> 1);
            int count = 0;
            for(int i = 0; i < size; ++ i)
                if(nums[i] <= m) ++ count;
                
            if(count > m) r = m;
            else l = m + 1;
        }
        return l;
    }
};
