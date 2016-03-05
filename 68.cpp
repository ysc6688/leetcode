class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        if( words.size() == 0 ) return words;
        int i,j,size;
        
        i = size = j = 0;
        while(1)
        {
            if(i < words.size() && words[i].size() + size + j <= maxWidth)
            {
                size += words[i].size();
                j += 1;
                i += 1;
                continue;
            }
            else
            {
                int blank = maxWidth - size;
                int each;
                int more;
                
                string line = "";

                if(j != 1)
                {
                    each = blank / (j - 1);
                    more = blank % (j - 1);
                
                    if(i < words.size()) {
                        for(int ii=i-j;ii<i-1;++ii)
                        {
                            line += words[ii];
                            for(int jj=0;jj<each;++jj) line += " ";
                            if( more )
                            {
                                line += " ";
                                --more;
                            }
                        }
                        line += words[i - 1];
                    }
                    else {
                        for(int ii=i-j;ii<i;++ii)
                        {
                            line += words[ii];
                            line += " ";
                        }
                        for(int ii=0;ii<blank-j;++ii)
                            line += " ";
                    }
                }
                else
                {
                    line += words[i-j];
                    for(int ii=0;ii<blank;++ii) line += " ";
                }
                result.push_back(line);
                if( i < words.size() )
                    size = j = 0;
                else
                    break;
            }
        }
        return result;
    }
};
