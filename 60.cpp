class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        for(int i=0;i<=n;++i)
            v.push_back(i);
        string res = "";
        int nn = n;

        while(v.size() > 1) {
            int count = 1;
            for(int i=1;i<n;++i)
                count *= i;
            int p = (k - 1) / count;
            int i = 1 + p;

            res += '0' + v[i];
            v.erase(v.begin()+i);
            k = k - count * p;
            n = n - 1;
        }
        return res;
    }
};
