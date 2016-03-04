class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num){
    int i,j;
    std::multimap<int, int> mp;
    vector< vector<int> > *r;
    map<int,int>::iterator iter,t;

    r = new vector< vector<int> >;

    if(num.size() < 3)
        return *r;

    sort(num.begin(),num.end());

    for (i = 0; i < (int)num.size(); ++i)
    {
        mp.insert(make_pair(num.at(i),i));
    }
    for (i = 0; i < (int)num.size(); ++i)
    {
        if(i>0 && num.at(i)==num.at(i-1))
            continue;
        if(num.at(i)>0 || (num.at(i)==0&&i+1<num.size()&&num.at(i+1)>0))
            break;
        for (j = i+1; j < (int)num.size(); ++j)
        {
            if(j-1!=i&&num.at(j)==num.at(j-1))
                    continue;
            int a = num.at(i);
            int b = num.at(j);
            int k = 0 - a - b;
            int flag;
            iter = mp.lower_bound(k);
            if(iter->first != k)
                continue;
            while(iter->first==k)
            {
                t = iter;
                iter++;
            }
            iter = t;
            if(iter->second!=i && iter->second!=j && iter->second>j)
            {
                std::vector<int> v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(k);
                sort(v.begin(),v.end());
                r->push_back(v);
            }
        }
    }
    return *r;

}
};
