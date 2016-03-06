class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if( !size ) return 0;
        if( size == 1) return 1;
    
        vector<int> res(size,1);
        
        res[0] = 1;
        
        for(int i = 1; i < size; ++ i)
        {
            if(ratings[i] > ratings[i - 1])
                res[i] = res[i - 1] + 1;
        }
        for(int i = size - 2; i >= 0; -- i)
        {
            if(ratings[i] > ratings[i + 1] && res[i] <= res[i + 1])
                res[i] = res[i + 1] + 1;
        }
        
        int sum = 0;
        for(int i = 0; i < size; ++ i)
            sum += res[i];
        return sum;
    }
};
