class Solution {
    vector<vector<int>> r;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> s;
        sort(candidates.begin(),candidates.end());
        process(candidates,target,s,0);
        return r;
    }
    
    bool process(vector<int>& candidates, int target, vector<int> s, int ii){
        for(int i=ii;i<candidates.size();++i)
        {
            if(target < candidates[i])
                return false;
            else if(target == candidates[i])
            {
                s.push_back(candidates[i]);
                r.push_back(s);
                return true;
            }
            else
            {
                s.push_back(candidates[i]);
                target -= candidates[i];
                process(candidates, target, s, i);
                target += s.back();
                s.pop_back();
            }
        }
    }
};
