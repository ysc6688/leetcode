class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        reverse(s.begin(),s.end());
        int index = 0;
        while(index<s.size() && (s[index]<'A' || s[index]>'Z'&&s[index]<'a' || s[index]>'z') ) ++index;
        if(index == s.size())
            return 0;
        for(int i=index;i<s.size();++i)
        {
            if(s[i]>='A'&&s[i]<='Z' || s[i]>='a'&&s[i]<='z')
                count++;
            else
                break;
        }
        return count;
    }
};
