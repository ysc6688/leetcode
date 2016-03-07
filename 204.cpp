class Solution {
public:
    int countPrimes(int n) {
        bool isPrime[n];
        memset(isPrime,true,sizeof(bool) * n);
        
        for(int i = 4; i < n; i += 2)
            isPrime[i] = false;
        
        for(int i = 3; i * i < n; ++ i)
        {
            if( !isPrime[i] ) continue;
            int k = 2 * i;
            for(int j = i * i; j < n; j += k)
                isPrime[j] = false;
        }
        
        int res = 0;
        for(int i = 2; i < n; ++ i)
            if( isPrime[i] ) ++ res;
            
        return res;
    }
};
