class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size,profit,last;
        size = prices.size();
        
        if(size < 2) return 0;
        
        profit = 0;
        bool isbuy = false;
        
        for(int i=0;i<size - 1;++i)
        {
            if( !isbuy )
            {
                if(prices[i] >= prices[i + 1]) continue;
                else
                {
                    last = prices[i];
                    isbuy = true;
                }
            }
            else
            {
                if(prices[i] <= prices[i + 1]) continue;
                else
                {
                    profit += prices[i] - last;
                    isbuy = false;
                }
            }
        }
        if( isbuy && prices[size - 1] > last)
            profit += prices[size - 1] - last;
        return profit;
    }
};
