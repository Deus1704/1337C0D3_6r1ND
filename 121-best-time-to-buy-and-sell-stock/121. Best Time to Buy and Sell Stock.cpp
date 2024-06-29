class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy = prices[0];
        int n = prices.size();
        for (int i=1; i<n; i++){
            if (prices[i]<buy) buy = prices[i];
            else if (prices[i]-buy > max_profit) max_profit = prices[i]-buy; 
        }
        return max_profit;
    }
};
