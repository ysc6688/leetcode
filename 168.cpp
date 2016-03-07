class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 0)
        {
            char c = 'A' + (n - 1) % 26;
            res += c;
            n = (n - 1) / 26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
