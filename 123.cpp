class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size < 2) return 0;
        
        int p1[size],p2[size],min,max;
        int profit = 0;
        
        min = prices[0];
        
        p1[0] = p2[size-1] = 0;
        
        for(int i=1;i<size;++i)
        {
            if(prices[i] < min)
                min = prices[i];
            if(p1[i-1] < prices[i] - min)
                p1[i] = prices[i] - min;
            else
                p1[i] = p1[i-1];
        }
        
        max = prices[size-1];
        for(int i=size - 2;i>=0;--i)
        {
            if(prices[i] > max)
                max = prices[i];
            if(p2[i+1] < max - prices[i])
                p2[i] = max - prices[i];
            else
                p2[i] = p2[i+1];
        }
        
        
        for(int i=0;i<size;++i)
        {
            if(profit < p1[i] + p2[i])
                profit = p1[i] + p2[i];
        }
        
        return profit;
    }
};
