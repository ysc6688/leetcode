class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n <= 0 || primes.size() == 0) return 0;
        
        int size = primes.size();
        vector<int> v(size,0);
        vector<int> res(n);
        
        res[0] = 1;
        int k = 1;
        while(k < n)
        {
            int min = INT_MAX;
            int index = -1;
            for(int i = 0; i < size; ++ i)
            {
                if(res[v[i]] * primes[i] < min)
                {
                    min = res[v[i]] * primes[i];
                    index = i;
                }
            }
            
            res[k ++] = min;
            v[index] ++;
            
            for(int i = 0; i < size; ++ i)
                while(res[v[i]] * primes[i] <= min) ++ v[i];
        }
        
        return res[n - 1];
    }
};
