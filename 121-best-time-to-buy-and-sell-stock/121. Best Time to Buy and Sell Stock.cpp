class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int n = prices.size();
        int l=0,r=0;
        while (r<n){
            if (prices[r]>prices[l]) max_profit = max(max_profit, prices[r]-prices[l]);
            else{
                l=r;
            }
            r++;
        }
        return max_profit;
    }
};
