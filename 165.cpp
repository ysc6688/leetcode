class Solution {
public:
    int point(string s)
    {
        int size = s.size();
        for(int i = 0; i < size; ++ i)
            if(s[i] == '.') return i;
        return size;
    }
    
    int cmp(string s1, string s2)
    {
        int p1 = point(s1);
        int p2 = point(s2);
        
        string s1_first = s1.substr(0,p1);
        string s2_first = s2.substr(0,p2);

        int i1 = atoi(s1_first.c_str());
        int i2 = atoi(s2_first.c_str());
        if( i1 > i2 ) return 1;
        else if(i1 < i2 ) return -1;
        else
        {
            if( p1 == s1.size() && p2 == s2.size() ) return 0;
            else if( p1 == s1.size() ) s1 += ".0";
            else if( p2 == s2.size() ) s2 += ".0";
            
            string s1_second = s1.substr(p1 + 1,s1.size() - p1 - 1);
            string s2_second = s2.substr(p2 + 1,s2.size() - p2 - 1);
            return cmp(s1_second,s2_second);
        }
    }
    
    int compareVersion(string version1, string version2) {
        return cmp(version1,version2);
    }
};
