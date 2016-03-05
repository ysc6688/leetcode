class Solution {
public:
    string minWindow(string s, string t) {
        if( s.empty() || t.empty() ) return "";
        
        int count = t.size();
        int re[128] = { 0 };
        bool b[128] = { false };
        int i,j;
        int size = s.size();
        int min = size + 1;
        string result = "";

        for(i=0;i<count;++i)
        {
            re[t[i]]++;
            b[t[i]] = true;
        }
        i = -1;
        j = 0;
        while(i<size && j<size)
        {
            if( count )
            {
                ++i;
                if(re[s[i]] > 0)
                    count--;
                if( b[s[i]] )
                    re[s[i]]--;
            }
            else
            {
                if(min > i - j + 1)
                {
                    min = i - j + 1;
                    result = s.substr(j,min);
                }
                if( b[s[j]] )
                    re[s[j]]++;
                if( re[s[j]] > 0)
                    count++;
                ++j;
            }
        }
        return result;
    }
};
