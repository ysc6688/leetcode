class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if( size < 2 ) return 0;
        
        int max = 0, min = prices[0];
        for(int i=1;i<size;++i)
        {
            if(prices[i] < min)
                min = prices[i];
            if(max < prices[i] - min)
                max = prices[i] - min;
        }
        
        return max;
    }
};
