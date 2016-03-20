class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        if( !size ) return ;
        
        int l,r;
        l = r = 0;
        while(l < size && nums[l] != 0) ++ l;
        
        if(l == size) return ;
        
        r = l + 1;
        
        while(r < size)
        {
            while(r < size && nums[r] == 0) ++ r;
            if(r == size) break ;
            nums[l ++] = nums[r ++];
        }
        
        for( ; l < size; ++ l) nums[l] = 0;
    }
};
