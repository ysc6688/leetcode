class Solution {
public:
    void combine(int k, int c, int n, vector<int>& s, vector<vector<int>>& res)
    {
        if(c == k && n == 0)
            res.push_back(s);
        else if( (c == k && n > 0) || n <= 0)
            return ;
        else {
            int i = s.empty() ? 1 : (s.back() + 1);
            for(; i < 10; ++ i)
            {
                s.push_back(i);
                n -= i;
                ++ c;
                combine(k,c,n,s,res);
                s.pop_back();
                n += i;
                -- c;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(n < k || n <= 0 || k <= 0) return res;
        
        vector<int> s;
        combine(k,0,n,s,res);
        return res;
    }
};
