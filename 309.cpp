class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if( size < 2 ) return 0;
        
        int profit[size] = { 0 };
        int profit_ign[size] = { 0 };
        
        if(prices[1] > prices[0]) profit[1] = prices[1] - prices[0];
        profit_ign[1] = profit[1];

        for(int i = 2; i < size; ++ i)
        {
            profit_ign[i] = std::max(profit[i - 2], prices[i] - prices[i - 1] + profit_ign[i - 1]);
            profit[i] = std::max(profit[i - 1],profit_ign[i]);
        }
        return profit[size - 1];
    }
};
