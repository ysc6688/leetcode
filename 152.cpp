class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if( !size ) return 0;
        if( size == 1 ) return nums[0];
        
        int min,max,res;
        
        res = min = max = nums[0];
        
        for(int i = 1; i < size; ++ i)
        {
            int a = max * nums[i];
            int b = min * nums[i];
            
            max = std::max(nums[i],std::max(a,b));
            min = std::min(nums[i],std::min(a,b));
            
            res = std::max(max,res);
        }
        
        return res;
    }
};
