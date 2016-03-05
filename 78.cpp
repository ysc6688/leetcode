class Solution {
    vector<vector<int>> result;
public:
    void dfs(vector<int>& v, int t, vector<int>& nums)
    {
        result.push_back(v);
        for(int i=t;i<nums.size();++i)
        {
            v.push_back(nums[i]);
            dfs(v,i+1,nums);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        dfs(v,0,nums);
        return result;
    }
};
