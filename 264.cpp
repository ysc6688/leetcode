class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return 0;
        
        vector<int> v(n);
        v[0] = 1;
    
        int mul2,mul3,mul5;
        mul2 = mul3 = mul5 = 0;
        int next = 1;
        while(next < n)
        {
            int min = std::min(v[mul2] * 2,std::min(v[mul3] * 3,v[mul5] * 5));
            v[next] = min;
            while(v[mul2] * 2 <= min) ++ mul2;
            while(v[mul3] * 3 <= min) ++ mul3;
            while(v[mul5] * 5 <= min) ++ mul5;
            
            ++ next;
        }
        return v[n - 1];
    }
};
