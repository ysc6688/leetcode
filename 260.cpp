class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        int size = nums.size();
        if( !size ) return res;
        
        int dif = 0;
        for(int i = 0; i < size; ++ i)
            dif ^= nums[i];
            
        int bit = 1;
        for(int i = 0; i < 32; ++ i)
        {
            if(bit & dif) break;
            else{
                bit = bit << 1;
            }
        }
        
        int first,second;
        first = second = 0;
        
        for(int i = 0; i < size; ++ i)
        {
            if(nums[i] & bit) first ^= nums[i];
            else second ^= nums[i];
        }
        res.push_back(first);
        res.push_back(second);
        
        return res;
    }
};
