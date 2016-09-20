class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int len = A.size();
        if(len < 2) return 0;
        
        int sum = 0;
        for(int i = 0; i < len; ++ i)
            sum += A[i];
        
        vector<int> nums(len);
        for(int i = 0; i < len; ++ i)
            nums[i] = sum - A[i];
            
        int last = 0;
        for(int i = 0; i < len; ++ i)
            last += i * A[i];
        
        int res = last;
        for(int i = 1; i < len; ++ i)
        {
            int f = last + nums[len - i] - (len - 1) * A[len - i];
            res = std::max(f, res);
            last = f;
        }
        
        return res;
    }
};
