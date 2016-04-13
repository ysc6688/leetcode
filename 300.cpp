class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if( !size ) return 0;
        
        int dp[size + 1] = { 0 };
        dp[0] = INT_MIN;
        dp[1] = nums[0];
        
        int res = 1;
        for(int i = 1; i < size; ++ i)
        {
            int l,r,m;
            l = 1;
            r = res;
            while(l <= r)
            {
                m = l + ((r - l) >> 1);
                if(dp[m] == nums[i]) {
                    l = m;
                    break;
                }
                else if(dp[m] > nums[i]) r = m - 1;
                else l = m + 1;
            }
            dp[l] = nums[i];
            if(l > res) res = l;
        }
        return res;
    }
};
