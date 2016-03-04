class Solution {
    vector<vector<int> > res;
public:
    void dfs(vector<int>& nums,vector<int>& f,vector<int>& t)
    {
        if(t.size() == nums.size())
        {
            res.push_back(t);
            return ;
        }
        for(int i=0;i<nums.size();++i)
        {
            if(f[i] == 0)
            {
                t.push_back(nums[i]);
                f[i] = 1;
                dfs(nums,f,t);
                f[i] = 0;
                t.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return res;
        vector<int> f(nums.size(),0),t;
        dfs(nums,f,t);
        return res;
    }
};
