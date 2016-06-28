class Solution {
public:
    int getOne(int i)
    {
        int count = 0;
        while( i )
        {
            ++ count;
            i = i & (i - 1);
        }
        return count;
    }
    vector<int> countBits(int num) {
        vector<int> res(num + 1,0);
        for(int i = 1; i <= num; ++ i)
            res[i] = getOne(i);
        return res;
    }
};
