class Solution {
public:
    int rec(int amount, vector<int>& coins, int index, vector<vector<int>>&dp ){
        // base case
        if (amount ==0 && index<=coins.size()) return 1;
        if (index==coins.size() || amount<0) return 0;
        if (dp[index][amount]!=-1) return dp[index][amount];
        int take_ways = 0, not_take_move = 0;
        // Take and Stay
        take_ways =  rec(amount-coins[index], coins, index, dp);
        // Not Take and move
        not_take_move = rec(amount, coins, index+1, dp);
        return dp[index][amount] = take_ways + not_take_move ;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return rec(amount, coins, 0, dp);
    }
};