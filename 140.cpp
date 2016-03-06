class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        int size = s.size();
        if( !size ) return res;
        
        vector<int> isb(size + 1);
        isb[0] = 1;
        
        vector<vector<string>> record(size + 1);
        
        for(int i = 1; i <= size; ++ i)
            for(int j = i - 1; j > -1; -- j)
            {
                if( isb[j] && wordDict.find(s.substr(j,i - j)) != wordDict.end() )
                {
                    isb[i] = 1;
                    break;
                }
            }
            
        if( !isb[size] ) return res;

        for(int i = 1; i <= size; ++ i)
        {
            if( !isb[i] ) continue;
            for(int j = i - 1; j > -1; -- j)
            {
                if( isb[j] && wordDict.find(s.substr(j,i - j)) != wordDict.end() )
                {
                    isb[i] = 1;
                    if(record[j].size() == 0)
                    {
                        record[i].push_back(s.substr(j,i - j));
                    }
                    else
                    {
                        string temp = s.substr(j,i - j);
                        for(int k = 0; k < record[j].size(); ++ k)
                        {
                            record[i].push_back(record[j][k] + " " + temp);
                        }
                    }
                }
            }
        }
        res = record[size];
        return res;
    }
};
