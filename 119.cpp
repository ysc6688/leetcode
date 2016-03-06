class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        int last;
        
        res.resize(rowIndex+1);
        res[0] = 1;
        if( !rowIndex ) return res;
        
        for(int i=1;i<=rowIndex;++i)
        {
            res[0] = 1;
            for(int j=2;j<i+1;++j)
            {
                int k = res[j-2] + res[j-1];
                if(j > 2)
                {
                    res[j-2] = last;
                    last = k;
                }
                else
                    last = k;
            }
            if(i > 1) res[i - 1] = last;
            res[i] = 1;
        }
        return res;
    }
};
