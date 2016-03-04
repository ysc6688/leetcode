class Solution {
    vector<vector<int>> r;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> s;
        sort(candidates.begin(),candidates.end());
        process(candidates,target,s,-1);
        return r;
    }
    
    bool process(vector<int>& candidates, int target, vector<int> s, int ii){
        for(int i=ii+1;i<candidates.size();)
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
                int j = i + 1;
                while(j<candidates.size())
                {
                    if(candidates[i] == candidates[j])
                        ++j;
                    else
                        break;
                }
                i = j;
            }
        }
    }
};
