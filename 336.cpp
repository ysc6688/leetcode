class Solution {
public:
    bool ispalid(string s)
    {
        int len = s.size();
        if(len < 2) return true;
        
        int l = 0, r = len - 1;
        
        while(l < r)
        {
            if(s[l] != s[r]) return false;
            ++ l;
            -- r;
        }
        
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int size = words.size();
        vector<vector<int>> res;
        
        unordered_map<string,int> um;
        for(int i = 0; i < size; ++ i)
            um.insert(make_pair(words[i],i));
        
        for(int i = 0; i < size; ++ i)
        {
            string rs = words[i];
            reverse(rs.begin(),rs.end());
            int len = rs.size();
            
            for(int j = 0; j <= len; ++ j)
            {
                string left = rs.substr(0,j);
                string right = rs.substr(j);
                
                unordered_map<string,int>::iterator r_it = um.find(right);
                if(r_it != um.end() && ispalid(left) && r_it->second != i)
                    res.push_back(vector<int>({i,r_it->second}));
                    
                unordered_map<string,int>::iterator l_it = um.find(left);
                if(l_it != um.end() && ispalid(right) && l_it->second != i && j < len)
                    res.push_back(vector<int>({l_it->second,i}));
            }
        }
            
        return res;
    }
};
