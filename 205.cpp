class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int size = s.size();
        char alph[128] = { 0 };
        bool isuse[128];
        memset(isuse,false,128);
        
        for(int i = 0; i < size; ++ i)
        {
            int key = s[i] - '\0';
            int value = t[i] - '\0';
            if( !alph[key] && !isuse[value]) 
            {
                alph[key] = t[i];
                isuse[value] = true;
            }
            else if(alph[key] != t[i])
                return false;
        }

        return true;
    }
};
