//Anagrams
class Solution {
private:
        map<string,vector<string> >m;
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        ret.clear();
        m.clear();
        for(int i = 0 ; i < strs.size() ; i++)
        {
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            
            m[tmp].push_back(strs[i]);
        }
        for(map<string,vector<string> >::iterator it = m.begin(); it != m.end(); it++)
        {
            if ( (it->second).size() > 1 )
            {
                for(vector<string>::iterator it1 = (it->second).begin(); it1!= (it->second).end(); it1++)
                    ret.push_back(*it1);
            }
        }
        return ret;
    }
};
