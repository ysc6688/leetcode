class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if( n == 0 || ~n == 0 ) return n;
        uint32_t key,res,val;
        res = 0;
        key = 1;
        val = 0x80000000;
        
        for(int i = 0; i < 32; ++ i)
        {
            if(n & key) res |= val;
            key = key << 1;
            val = val >> 1;
        }
        return res;
    }
};
