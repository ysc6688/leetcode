class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = words.size();
        if(size < 2) return 0;
        
        vector<int> v(size,0);
        
        for(int i = 0; i < size; ++ i)
        {
            for(int j = 0; j < words[i].size(); ++ j)
                v[i] |= 1 << (words[i][j] - 'a');
        }
        
        int res = 0;
        for(int i = 0; i < size; ++ i)
            for(int j = i + 1; j < size; ++ j)
            {
                if(v[i] & v[j]) continue;
                int product = words[i].size() * words[j].size();
                res = std::max(res,product);
            }
            
        return res;
    }
};
