class Solution {
public:
    string convert(string s,int nRows)
{
    int zz;//zz is 1 when zig and -1 when zag
    int i,count;
    std::vector<char> v[1000];
    
    if(nRows == 1)
        return s;

    zz = 1;
    count = 0;
    for (i = 0; i < (int)s.size(); ++i)
    {
        v[count].push_back(s.at(i));
        count += zz;
        if(count == nRows)
        {
            zz = -1;
            count -= 2;
        }
        if(count == -1)
        {
            zz = 1;
            count += 2;
        }
    }
    s.clear();
    for (i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < (int)v[i].size(); ++j)
        {
            s += v[i].at(j);
        }
    }
    return s;
}
};
