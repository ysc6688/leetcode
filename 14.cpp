class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        string r;
        int i,j = 0;
        
        if(n == 0)
            return "";
        while(1)
        {
            char c = strs.at(0)[j];
            if(c == 0)
                return r;
            for(i=1;i<n;i++)
            {
                if(strs.at(i)[j] != c)
                    return r;
            }
            r += c;
            j++;
        }
    }
};
