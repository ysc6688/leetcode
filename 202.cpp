class Solution {
public:
    int gethappy(int n)
    {
        int res = 0;
        while( n )
        {
            int num = n % 10;
            res += num * num;
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        if( n == 1 ) return true;
        
        bool hash[1000];
        memset(hash,false,sizeof(bool) * 1000);
        while( 1 )
        {
            int key = gethappy(n);
            if(key == 1) return true;
            else if( hash[key] ) return false;
            else
            {
                hash[key] = true;
                n = key;
            }
        }
    }
};
