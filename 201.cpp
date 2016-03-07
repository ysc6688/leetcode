class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n) return m;
        
        int res = 0;
        bool bit[2][31];
        memset(bit,false,sizeof(bool)*2*31);
        int flag = 1;
        int i = 30;
        while(m || n)
        {
            if(m & flag){
                bit[0][i] = true;
                m -= flag;
            }
            if(n & flag){
                bit[1][i] = true;
                n -= flag;
            }
            -- i;
            flag = flag << 1;
        }
        flag = 0x40000000 >> ++i;
        for( ; i < 31; ++ i)
        {
            if( bit[0][i] && bit[1][i] ) res |= flag;
            else if( bit[0][i] | bit[1][i] ) break;
            
            flag = flag >> 1;
        }
        return res;
    }
};
