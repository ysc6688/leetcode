class Solution {
public:
    void dfs(vector<int>& nums,int i,vector<int>& aset, vector<vector<int>>& result)
    {
        int size = nums.size();
        for(int j=i;j<size;++j)
        {
            aset.push_back(nums[j]);
            result.push_back(aset);
            dfs(nums,j+1,aset,result);
            aset.pop_back();
            while(j<size-1 && nums[j]==nums[j+1]) ++j;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> aset;
        result.push_back(aset);
        if(nums.size() == 0) return result;
        
        sort(nums.begin(),nums.end());
        
        dfs(nums,0,aset,result);
        return result;
    }
};
