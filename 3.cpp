class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int hash[128] = {0};
    int length = 0,i = 0,flag,max = 0,start = 0;
    while(i < (int)s.length())
    {
        flag = s.at(i) - '\0';
        if(hash[flag] == 0)
        {
            length++;
            if(length > max)
                max = length;
            i++;
            hash[flag] = 1;
        }
        else
        {
            length = 0;
            i = start + 1;
            start = i;
            for (int j = 0; j < 128; ++j)
                hash[j] = 0;
        }
    }
    return max;
    }
};
