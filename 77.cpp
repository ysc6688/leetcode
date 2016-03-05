class Solution {
    vector<vector<int>> result;
public:
    void dfs(vector<int> &l, int i, int n, int k)
    {
        if(l.size() == k)
        {
            result.push_back(l);
            return ;
        }
        for(int j=i;j<=n;j++)
        {
            l.push_back(j);
            dfs(l,j+1,n,k);
            l.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> l;
        dfs(l,1,n,k);
        
        return result;
    }
};
