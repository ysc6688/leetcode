class Solution {
    vector<vector<int> > res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0) return res;
        vector<int> f(nums.size(),0),t;
        
        sort(nums.begin(),nums.end());
        
        dfs(nums,f,t);
        
        return res;
    }
    void dfs(vector<int>& nums,vector<int>& f,vector<int>& t)
    {
        if(t.size() == nums.size())
        {
            res.push_back(t);
            return ;
        }
        for(int i=0;i<nums.size();++i)
        {
            if(i>0 && nums[i] == nums[i-1] && f[i-1]==0)
                continue;
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
};
