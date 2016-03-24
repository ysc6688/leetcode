class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int size = str.size();
        vector<string> vs;
        int i = 0;
        while(i < size)
        {
            int begin = i;
            while(i < size && str[i] != ' ') ++ i;
            vs.push_back(str.substr(begin,i - begin));
            ++ i;
        }
        
        if(pattern.size() != vs.size()) return false;
        
        vector<string> ht(26,"");
        unordered_set<string> set;

        size = vs.size();
        
        for(int i = 0; i < size; ++ i)
        {
            int key = pattern[i] - 'a';
            
            if(ht[key] == "" && set.find(vs[i]) == set.end())
            {
                ht[key] = vs[i];
                set.insert(vs[i]);
            }
            else if(ht[key] == "" && set.find(vs[i]) != set.end())
                return false;
            else if(ht[key] != "" && ht[key] != vs[i])
                return false;
        }
    
        
        return true;
    }
};
