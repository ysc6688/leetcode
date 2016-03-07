class Solution {
public:
    int mydiv(int a, int b)
    {
        int flag = 1;
        if(a < 0){
            a = -a;
            flag = -flag;
        }
        if(b < 0){
            b = -b;
            flag = -flag;
        }
        int r = 0;
        int c = b;
        
        while(a > c)
        {
            c <<= 1;
        }
        
        while(c >= b)
        {
            r <<= 1;
            if(a >= c)
            {
                ++ r;
                a -= c;
            }
            c >>= 1;
        }
        if(flag < 0) r = -r;
        return r;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size);
        if( !size ) return res;

        long pro = 1;
        int count = 0;
        int pos;
        for(int i = 0; i < size; ++ i)
        {
            if(nums[i] == 0) 
            {
                if(++ count > 1) break;
                pos = i;
            }
            else pro *= nums[i];
        }
        
        if(count > 1) return res;
        else if( count == 1 ) {
            res[pos] = pro;
            return res;
        }
            
        for(int i = 0; i < size; ++ i)
        {
            res[i] = pro / nums[i];
        }
        return res;
    }
};
