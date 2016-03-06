class Solution {
public:
    bool isPalind(string s)
    {
        if(s.size() == 1) return true;
        else
        {
            int l = 0, r = s.size() - 1;
            while(l < r)
            {
                if(s[l] == s[r])
                {
                    ++l;
                    --r;
                }
                else return false;
            }
            return true;
        }
    }
    
    void dopartition(string s, vector<vector<string>>& res, vector<string>& elem)
    {
        int size = s.size();
        if( isPalind(s) )
        {
            elem.push_back(s);
            res.push_back(elem);
            elem.pop_back();
        }
        
        for(int i = 1; i < size; ++ i)
        {
            string substr = s.substr(0,i);
            if( !isPalind(substr) ) continue;
            else
            {
                elem.push_back(substr);
                dopartition(s.substr(i,size - i),res,elem);
                elem.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s == "") return res;
        
        vector<string> elem;
        dopartition(s,res,elem);
        return res;
    }
};
