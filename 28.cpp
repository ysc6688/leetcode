class Solution {
public:
    void prefix(int *next, char *str){
        int i,j,size;
        size = strlen(str);
        next[0] = 0;
        for(i=1;i<size;++i)
        {
            register int k = next[i-1];
            while(k!=0 && str[k]!=str[i])
                k = next[k-1];
            if(str[k] == str[i])
                next[i] = k + 1;
            else
                next[i] = 0;
        }
    }
    int strStr(char *haystack,char *needle) {
        int i,j;
        int lh = strlen(haystack);
        int ln = strlen(needle);
        if(ln > lh)
            return -1;
        if(ln == 0)
            return 0;
        i = j = 0;
        int *next = new int[lh];
        prefix(next,needle);
        while(i < lh)
        {
            if(haystack[i] == needle[j])
            {
                if(j == ln-1)
                {
                    delete [] next;
                    return i-j;
                }
                else
                {
                    ++i;
                    ++j;
                }
            }
            else{
                if(j == 0)
                    ++i;
                else
                    j = next[j-1];
            }
        }
        delete []next;
        return -1;
    }
};
