class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int l_size = L.size();
        int word_size = L[0].size();
        int i,j;
        vector<int> v;
        map<string,int> word_count;
        
        if( !l_size )
            return v;
        
        for(i=0;i<l_size;++i)
            ++word_count[L[i]];
        map<string,int> tmp;
        for(i=0;i<=(int)S.length()-l_size*word_size;++i)
        {
            tmp.clear();
            for(j=0;j<l_size;++j)
            {
                string sub = S.substr(i+j*word_size,word_size);
                if(word_count.find(sub) != word_count.end())
                {
                    ++tmp[sub];
                    if(tmp[sub] > word_count[sub])
                        break;
                }
                else
                    break;
            }
            if(j==l_size)
                v.push_back(i);
        }
        return v;
    }
};
